all: build


build : main.cc
	@echo 'Compiling...'
	@g++ main.cc -o CC -lgmpxx -lgmp
	@echo 'done.'



test: 
	@./Collatz-Conjecture

