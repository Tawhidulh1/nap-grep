
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:src/%.c=build/%.o)

# For future references: ng depends on all OBJS (all build/*.o) and $^ is talking about the dependecies of ng(the target) and $@ is the target/ng
ng: $(OBJS)
	gcc $^ -o $@

build/%.o: src/%.c
	@mkdir -p build
	gcc -Wall -Wextra -g -MMD -MP -c $< -o $@ 

-include $(OBJS:.o=.d)

.PHONY: clean
clean:
	rm -rf build ng
