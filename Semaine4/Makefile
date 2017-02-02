TARGETS=accolades_ou_crochets.pdf types_c.pdf

all: $(TARGETS)

%.pdf : %.md
	~/.cabal/bin/pandoc -t beamer $< --highlight-style=zenburn -o $@

%.dot.png : %.dot
	dot -Tpng < $< > $@

clean :
	rm -f $(TARGETS) *.dot.png
