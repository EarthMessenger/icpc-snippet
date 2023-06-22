LATEXMK=/usr/bin/latexmk
LATEXMKFLAGS=-xelatex -shell-escape

doc/icpc.pdf: doc/icpc.tex
	$(LATEXMK) $(LATEXMKFLAGS) $<

clean-doc:
	$(LATEXMK) -C doc/icpc.tex

.PHONY: clean-doc
