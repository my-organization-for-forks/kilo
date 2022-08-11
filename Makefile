bin/ft_kilo: src/main.o src/ft/ft_exit.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^
