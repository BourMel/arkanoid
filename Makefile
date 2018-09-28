.PHONY: arkanoid
arkanoid:
	g++ *.cpp *.h -lSDL2 -o arkanoid

.PHONY: format
format:
	clang-format -i *.cpp *.h

.PHONY: run
run:
	./arkanoid

.PHONY: clean
clean:
	rm arkanoid
