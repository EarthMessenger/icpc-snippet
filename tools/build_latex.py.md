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
  code: "#!/usr/bin/python\n\nfrom sys import argv\nfrom os import chdir\nfrom pathlib\
    \ import Path\nfrom subprocess import run\nfrom pygments.lexers import get_lexer_for_filename\n\
    \nEXCLUDED_FILES = [\n    'splay.hpp',\n]\n\ndef main():\n    print(r'''\n\\documentclass{article}\n\
    \n\\usepackage{ctex}\n\\usepackage{geometry}\n\\usepackage{minted}\n\n\\title{\u6A21\
    \u677F}\n\\author{emsger, robinyqc}\n\\date{\\today}\n\\geometry{a4paper, scale=0.8}\n\
    \\usemintedstyle{bw}\n\n\\begin{document}\n\n\\maketitle\n\\tableofcontents\n\\\
    clearpage\n    ''')\n\n    def dfs_dir(path, dep = -1):\n        if path.name\
    \ in EXCLUDED_FILES:\n            return\n        stem = path.stem.replace('_',\
    \ ' ')\n        if dep == 0:\n            print(fr'\\section{{{stem}}}')\n   \
    \     elif dep == 1:\n            print(fr'\\subsection{{{stem}}}')\n        elif\
    \ dep == 2:\n            print(fr'\\subsubsection{{{stem}}}')\n        if path.is_file():\n\
    \            print(fr'\\begin{{minted}}[breaklines, mathescape]{{{get_lexer_for_filename(path.name).aliases[0]}}}')\n\
    \            with path.open('r') as fo:\n                while True:\n       \
    \             line = fo.readline()\n                    if line == '':\n     \
    \                   break\n                    if line.strip() == '#pragma once':\n\
    \                        continue\n                    print(line.rstrip())\n\
    \            print(r'\\end{minted}')\n        elif path.is_dir():\n          \
    \  for child in path.iterdir():\n                dfs_dir(child, dep + 1)\n\n \
    \   dfs_dir(Path(argv[1]))\n\n    print(r'''\n\\end{document}\n          ''')\n\
    \nif __name__ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/build_latex.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/build_latex.py
layout: document
redirect_from:
- /library/tools/build_latex.py
- /library/tools/build_latex.py.html
title: tools/build_latex.py
---
