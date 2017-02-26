BINS = ensemble_chaine

.PHONY: all clean

all: $(BINS)

clean:
	rm -f $(BINS)

% : %.c
	gcc -Wall -Werror $< -o $@
