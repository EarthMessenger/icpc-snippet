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
    res = ''
    res += f'<h2>{file.relative_to(Path.cwd())}</h2>'
    code = ''
    with file.open('r') as fo:
        while True:
            line = fo.readline()
            if line == '':
                break
            if line.strip() == '#pragma once':
                continue
            code += line
    res += highlight(code, CppLexer(), HtmlFormatter())
    return res

def main():
    files = sorted(filter(lambda f: f.name not in EXCLUDED_FILES, Path.cwd().glob('**/*.hpp')))
    res = ''
    res += '<!doctype html>'
    res += '<head>'
    res += f'<style>{HtmlFormatter().get_style_defs()}</style>'
    res += '</head>'
    res += '<body>'
    res += ''.join((compile_html(f) for f in files))
    res += '</body>'
    with open('result.html', 'w') as resf:
        resf.write(res)

if __name__ == "__main__":
    main()
