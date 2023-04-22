srcs = $(wildcard *.c)
objs = $(srcs:.c=.o)
deps = $(srcs:.c=.d)

calc.app: $(objs)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -MMD -MP -c $< -o $@

.PHONY: clean

# $(RM) is rm -f by default
clean:
	$(RM) $(objs) $(deps) calc.app

-include $(deps)