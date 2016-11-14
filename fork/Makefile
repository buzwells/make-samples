# a generic make file for separate samples with main methods 
# illustrates variable use

# when you add a new sample, simply add the stem of the name to the TARGETS variable
TARGETS = fork-example two-forks

# now $(TARGETS) expands into the list you specified 
all: clean $(TARGETS) 

# loops through list in $(TARGETS) and effectively becomes a rule for each item
# $@ references the item
$(TARGETS): 
	$(CC) $@.c -o $@

clean:
	rm -f $(TARGETS)
