# a generic make file for separate samples with main methods
# illustrates variable use

# when you add a new sample, simply add the stem of the name to the TARGETS variable
TARGETS = thread-create thread-join thread-viz thread-share thread-bug1 thread-bug1-sol cond-var thread-bug2 thread-bug3 thread-bug3-sol thread-create-prob dotprod-mutex

# now $(TARGETS) expands into the list you specified
all: clean $(TARGETS)

# loops through list in $(TARGETS) and effectively becomes a rule for each item
# $@ references the item
$(TARGETS):
	$(CC) $@.c -o $@ -lpthread

clean:
	rm -f $(TARGETS)
