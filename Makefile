SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:src/%.c=build/%.o)

# For future references: ng depends on all OBJS (all build/*.o) and $^ is talking about the dependecies of ng(the target) and $@ is the target/ng
ng: $(OBJS)
	gcc $^ -o $@

build/%.o: src/%.c
	@mkdir -p build
	gcc -Wall -Wextra -g -MMD -MP -c $< -o $@ 

-include $(OBJS:.o=.d)

PREFIX ?= ~/.local
BINDIR := $(PREFIX)/bin

.PHONY: clean install uninstall
clean:
	rm -rf build ng

# DESTDIR for fakeroot
install: ng
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 ng $(DESTDIR)$(BINDIR)/ng

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/ng
