TARGETS=td1.pdf

all: $(TARGETS)

%.pdf : %.md
	~/.cabal/bin/pandoc -t beamer $< --highlight-style=zenburn -o $@

clean :
	rm -f $(TARGETS)
