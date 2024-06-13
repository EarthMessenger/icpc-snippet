build/template.tex: tools/build_latex.py
	python tools/build_latex.py lib > build/template.tex

build/template.pdf: build/template.tex
	cd build; latexmk -pdfxe -shell-escape template.tex

build/template.html: tools/build_html.py
	python tools/build_html.py > build/template.html

format:
	./tools/clang-format.sh

.PHONY: format
