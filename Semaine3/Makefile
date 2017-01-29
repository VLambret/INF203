TARGETS=flux_pipes.pdf compilation.pdf makefile.pdf

all: $(TARGETS)

makefile.md : make_tree1.dot.png

%.pdf : %.md
	~/.cabal/bin/pandoc -t beamer $< --highlight-style=zenburn -o $@

%.dot.png : %.dot
	dot -Tpng < $< > $@

clean :
	rm -f $(TARGETS) *.dot.png
