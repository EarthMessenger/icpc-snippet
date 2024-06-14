#!/usr/bin/env python3
# Adapted from ACL expander.py.

import re
import argparse
from logging import Logger, basicConfig, getLogger
from os import getenv, environ, pathsep
from pathlib import Path
from typing import List, Set


logger = getLogger(__name__)  # type: Logger


class Expander:

    def is_ignored_line(self, line) -> bool:
        if self.include_guard.match(line):
            return True
        if line.strip() == "#pragma once":
            return True
        if line.strip().startswith('//'):
            return True
        return False

    def __init__(self, lib_paths: List[Path], lib_name: str):
        self.lib_paths = lib_paths
        self.lib_include = re.compile(
        fr'#include\s*["<]({lib_name}/[a-z_/]*(|.hpp))[">]\s*')
        self.include_guard = re.compile(fr'#.*{lib_name.capitalize()}_[A-Z_]*_HPP')

    included = set()  # type: Set[Path]

    def find_lib(self, lib_name: str) -> Path:
        for lib_path in self.lib_paths:
            path = lib_path / lib_name
            if path.exists():
                return path
        logger.error('cannot find: {}'.format(lib_name))
        raise FileNotFoundError()

    def expand_lib(self, lib_file_path: Path) -> List[str]:
        if lib_file_path in self.included:
            logger.info('already included: {}'.format(lib_file_path.name))
            return []
        self.included.add(lib_file_path)
        logger.info('include: {}'.format(lib_file_path.name))

        lib_source = open(str(lib_file_path), encoding='utf-8').read()

        result = []  # type: List[str]
        for line in lib_source.splitlines():
            if self.is_ignored_line(line):
                continue

            m = self.lib_include.match(line)
            if m:
                name = m.group(1)
                result.extend(self.expand_lib(self.find_lib(name)))
                continue

            result.append(line)
        return result

    def expand(self, source: str) -> str:
        self.included = set()
        result = []  # type: List[str]
        for line in source.splitlines():
            m = self.lib_include.match(line)
            if m:
                lib_path = self.find_lib(m.group(1))
                result.extend(self.expand_lib(lib_path))
                continue

            result.append(line)
        return '\n'.join(result)


if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=getenv('LOG_LEVEL', 'INFO'),
    )
    parser = argparse.ArgumentParser(description='Expander')
    parser.add_argument('source', help='Source File')
    parser.add_argument('--console', '-c',
                        action='store_true', help='Print to Console')
    parser.add_argument('--libname', '-ln', help='Name List of Libraries', nargs='+', default=['lib'])
    parser.add_argument("--libpath", '-lp', help='Path List to Libraries', nargs='*')
    parser.add_argument('--inplace', '-i', action="store_true", 
                        help = "Replace the Old File with the Expanded One")
    parser.add_argument('--output', '-o', help="Output Filename", default="combined.cpp")

    opts = parser.parse_args()

    lib_paths = []
    if opts.libpath != None:
        for p in opts.libpath:
            lib_paths.append(Path(p))
    if 'CPLUS_INCLUDE_PATH' in environ:
        lib_paths.extend(
            map(Path, filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))
    lib_paths.append(Path.cwd())
    lib_names = opts.libname

    expander = Expander(lib_paths, lib_names[-1])
    output = expander.expand(open(opts.source, encoding='utf-8').read())
    while len(lib_names) > 1:
        lib_names.pop()
        expander = Expander(lib_paths, lib_names[-1])
        output = expander.expand(output)

    if opts.console:
        print(output)
    else:
        if opts.inplace:
            with open(opts.source, 'w', encoding='utf-8') as f:
                f.write(output)
        else:
            with open(opts.output, 'w', encoding='utf-8') as f:
                f.write(output)
