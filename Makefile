bin/ft_kilo: $(patsubst %.c,%.o,$(shell find src -name *.c))
	@mkdir -p $(@D)
	$(CC) -o $@ $^
