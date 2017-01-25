TARGETS=td1.pdf

all: $(TARGETS)

td1.pdf : filesystem.dot.png

%.pdf : %.md
	~/.cabal/bin/pandoc -t beamer $< --highlight-style=zenburn -o $@

%.dot.png : %.dot
	dot -Tpng < $< > $@

clean :
	rm -f $(TARGETS) *.dot.png
