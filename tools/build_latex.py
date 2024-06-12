#!/usr/bin/python

from sys import argv
from os import chdir
from pathlib import Path
from subprocess import run
from pygments.lexers import get_lexer_for_filename

EXCLUDED_FILES = [
    'splay.hpp',
]

def main():
    print(r'''
\documentclass{article}

\usepackage{ctex}
\usepackage{geometry}
\usepackage{minted}
\usepackage{multicol}

\title{模板}
\author{emsger, robinyqc}
\date{\today}
\geometry{a4paper, scale=0.8}
\usemintedstyle{bw}

\begin{document}

\maketitle
\tableofcontents
\clearpage

\begin{multicols}{2}
    ''')

    def dfs_dir(path, dep = -1):
        if path.name in EXCLUDED_FILES:
            return
        stem = path.stem.replace('_', ' ')
        if dep == 0:
            print(fr'\section{{{stem}}}')
        elif dep == 1:
            print(fr'\subsection{{{stem}}}')
        elif dep == 2:
            print(fr'\subsubsection{{{stem}}}')
        if path.is_file():
            print(fr'\begin{{minted}}[breaklines, mathescape]{{{get_lexer_for_filename(path.name).aliases[0]}}}')
            with path.open('r') as fo:
                while True:
                    line = fo.readline()
                    if line == '':
                        break
                    if line.strip() == '#pragma once':
                        continue
                    print(line.rstrip())
            print(r'\end{minted}')
        elif path.is_dir():
            for child in path.iterdir():
                dfs_dir(child, dep + 1)

    dfs_dir(Path(argv[1]))

    print(r'''
\end{multicols}
\end{document}
          ''')

if __name__ == "__main__":
    main()
