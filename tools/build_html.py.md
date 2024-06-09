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
  code: "#!/usr/bin/python\n\nimport sys\nfrom pathlib import Path\nfrom pygments\
    \ import highlight\nfrom pygments.lexers import CppLexer\nfrom pygments.formatters\
    \ import HtmlFormatter\n\nEXCLUDED_FILES = [\n    'splay.hpp',\n]\n\ndef compile_html(file):\n\
    \    res = ''\n    res += f'<h2>{file.relative_to(Path.cwd())}</h2>'\n    code\
    \ = ''\n    with file.open('r') as fo:\n        while True:\n            line\
    \ = fo.readline()\n            if line == '':\n                break\n       \
    \     if line.strip() == '#pragma once':\n                continue\n         \
    \   code += line\n    res += highlight(code, CppLexer(), HtmlFormatter())\n  \
    \  return res\n\ndef main():\n    files = sorted(filter(lambda f: f.name not in\
    \ EXCLUDED_FILES, Path.cwd().glob('**/*.hpp')))\n    res = ''\n    res += '<!doctype\
    \ html>'\n    res += '<head>'\n    res += f'<style>{HtmlFormatter().get_style_defs()}</style>'\n\
    \    res += '</head>'\n    res += '<body>'\n    res += ''.join((compile_html(f)\
    \ for f in files))\n    res += '</body>'\n    with open('result.html', 'w') as\
    \ resf:\n        resf.write(res)\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/build_html.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/build_html.py
layout: document
redirect_from:
- /library/tools/build_html.py
- /library/tools/build_html.py.html
title: tools/build_html.py
---
