a.out: main.cc map.h move.h actors.h battle.h weapon.h splash.h
	clang++ -stdlib=libc++ -std=c++0x main.cc
clean:
	rm a.out
