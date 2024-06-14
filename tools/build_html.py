#!/usr/bin/python

import sys
from pathlib import Path
from pygments import highlight
from pygments.lexers import CppLexer
from pygments.formatters import HtmlFormatter

EXCLUDED_FILES = [
    'splay.hpp',
]

def compile_html(file):
    print(f'<h2>{file.relative_to(Path.cwd())}</h2>')
    code = ''
    with file.open('r', encoding='utf-8') as fo:
        while True:
            line = fo.readline()
            if line == '':
                break
            if line.strip() == '#pragma once':
                continue
            code += line
    print(highlight(code, CppLexer(), HtmlFormatter()))

def main():
    files = sorted(filter(lambda f: f.name not in EXCLUDED_FILES, Path.cwd().glob('**/*.hpp')))
    print('<!doctype html>')
    print('<head>')
    print(f'<style>{HtmlFormatter().get_style_defs()}</style>')
    print('</head>')
    print('<body>')
    for f in files:
        compile_html(f)
    print('</body>')

if __name__ == "__main__":
    main()
