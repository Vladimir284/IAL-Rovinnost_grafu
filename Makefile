## Space for code


docBuild:
	latexmk -pdf doc/latex/documentary.tex

docClean:
	rm -f documentary.aux
	rm -f documentary.fdb_latexmk
	rm -f documentary.fls
	rm -f documentary.lof
	rm -f documentary.log
	rm -f documentary.lot
	rm -f documentary.out
	rm -f documentary.toc
	rm -f doc/latex/*.aux
	rm -f doc/latex/modules/*.aux

doc: docBuild docClean openDoc

clean: docClean

# Jus for now
openDoc:
	evince documentary.pdf