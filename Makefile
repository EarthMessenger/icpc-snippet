LATEXMK=/usr/bin/latexmk
LATEXMKFLAGS=-xelatex -shell-escape

icpc.pdf: icpc.tex
	$(LATEXMK) $(LATEXMKFLAGS) $<

clean:
	$(LATEXMK) -C

.PHONY: clean
