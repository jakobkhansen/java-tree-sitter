test:
	git submodule update --recursive --init
	./build.py -r src/test/grammars/* -o libparser
