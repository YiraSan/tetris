macos/build:
	mkdir -p bin/
	clang-19 src/main.c -Iinclude/ -o bin/venture -Llib/ -lSDL3.0
	install_name_tool -add_rpath lib/ bin/venture

macos/run: macos/build
	bin/venture
