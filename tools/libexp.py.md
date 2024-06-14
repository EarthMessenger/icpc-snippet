---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n# Adapted from ACL expander.py.\n\nimport re\nimport\
    \ argparse\nfrom logging import Logger, basicConfig, getLogger\nfrom os import\
    \ getenv, environ, pathsep\nfrom pathlib import Path\nfrom typing import List,\
    \ Set\n\n\nlogger = getLogger(__name__)  # type: Logger\n\n\nclass Expander:\n\
    \n    def is_ignored_line(self, line) -> bool:\n        if self.include_guard.match(line):\n\
    \            return True\n        if line.strip() == \"#pragma once\":\n     \
    \       return True\n        if line.strip().startswith('//'):\n            return\
    \ True\n        return False\n\n    def __init__(self, lib_paths: List[Path],\
    \ lib_name: str):\n        self.lib_paths = lib_paths\n        self.lib_include\
    \ = re.compile(\n        fr'#include\\s*[\"<]({lib_name}/[a-z_/]*(|.hpp))[\">]\\\
    s*')\n        self.include_guard = re.compile(fr'#.*{lib_name.capitalize()}_[A-Z_]*_HPP')\n\
    \n    included = set()  # type: Set[Path]\n\n    def find_lib(self, lib_name:\
    \ str) -> Path:\n        for lib_path in self.lib_paths:\n            path = lib_path\
    \ / lib_name\n            if path.exists():\n                return path\n   \
    \     logger.error('cannot find: {}'.format(lib_name))\n        raise FileNotFoundError()\n\
    \n    def expand_lib(self, lib_file_path: Path) -> List[str]:\n        if lib_file_path\
    \ in self.included:\n            logger.info('already included: {}'.format(lib_file_path.name))\n\
    \            return []\n        self.included.add(lib_file_path)\n        logger.info('include:\
    \ {}'.format(lib_file_path.name))\n\n        lib_source = open(str(lib_file_path),\
    \ encoding='utf-8').read()\n\n        result = []  # type: List[str]\n       \
    \ for line in lib_source.splitlines():\n            if self.is_ignored_line(line):\n\
    \                continue\n\n            m = self.lib_include.match(line)\n  \
    \          if m:\n                name = m.group(1)\n                result.extend(self.expand_lib(self.find_lib(name)))\n\
    \                continue\n\n            result.append(line)\n        return result\n\
    \n    def expand(self, source: str) -> str:\n        self.included = set()\n \
    \       result = []  # type: List[str]\n        for line in source.splitlines():\n\
    \            m = self.lib_include.match(line)\n            if m:\n           \
    \     lib_path = self.find_lib(m.group(1))\n                result.extend(self.expand_lib(lib_path))\n\
    \                continue\n\n            result.append(line)\n        return '\\\
    n'.join(result)\n\n\nif __name__ == \"__main__\":\n    basicConfig(\n        format=\"\
    %(asctime)s [%(levelname)s] %(message)s\",\n        datefmt=\"%H:%M:%S\",\n  \
    \      level=getenv('LOG_LEVEL', 'INFO'),\n    )\n    parser = argparse.ArgumentParser(description='Expander')\n\
    \    parser.add_argument('source', help='Source File')\n    parser.add_argument('--console',\
    \ '-c',\n                        action='store_true', help='Print to Console')\n\
    \    parser.add_argument('--libname', '-ln', help='Name List of Libraries', nargs='+',\
    \ default=['lib'])\n    parser.add_argument(\"--libpath\", '-lp', help='Path List\
    \ to Libraries', nargs='*')\n    parser.add_argument('--inplace', '-i', action=\"\
    store_true\", \n                        help = \"Replace the Old File with the\
    \ Expanded One\")\n    parser.add_argument('--output', '-o', help=\"Output Filename\"\
    , default=\"combined.cpp\")\n\n    opts = parser.parse_args()\n\n    lib_paths\
    \ = []\n    if opts.libpath != None:\n        for p in opts.libpath:\n       \
    \     lib_paths.append(Path(p))\n    if 'CPLUS_INCLUDE_PATH' in environ:\n   \
    \     lib_paths.extend(\n            map(Path, filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))\n\
    \    lib_paths.append(Path.cwd())\n    lib_names = opts.libname\n\n    expander\
    \ = Expander(lib_paths, lib_names[-1])\n    output = expander.expand(open(opts.source,\
    \ encoding='utf-8').read())\n    while len(lib_names) > 1:\n        lib_names.pop()\n\
    \        expander = Expander(lib_paths, lib_names[-1])\n        output = expander.expand(output)\n\
    \n    if opts.console:\n        print(output)\n    else:\n        if opts.inplace:\n\
    \            with open(opts.source, 'w', encoding='utf-8') as f:\n           \
    \     f.write(output)\n        else:\n            with open(opts.output, 'w',\
    \ encoding='utf-8') as f:\n                f.write(output)\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/libexp.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/libexp.py
layout: document
redirect_from:
- /library/tools/libexp.py
- /library/tools/libexp.py.html
title: tools/libexp.py
---
