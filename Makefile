.PHONY: clear check_fmt fmt test

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

test:
	@for test_file in $$(ls *_test 2>/dev/null); do \
		if [ -x "$$test_file" ]; then \
			echo "Running $$test_file..."; \
			./$$test_file || exit 1; \
		else \
			echo "$$test_file is not executable"; \
		fi \
	done

%_test: %_test.o %.a
	gcc -g -static -o $@ $< $*.a -lm

%.a: %.o
	ar rc $@ $<

%.o: %.c
	gcc -g -c $< -o $@
task5_integral/libintegral.a: task5_integral/src/integral.o
	ar rcs $@ $^
task5_integral/src/integral.o: task5_integral/src/integral.c task5_integral/include/integral.h
	gcc -c -Itask5_integral/include task5_integral/src/integral.c -o $@
task5_integral/test_integral: task5_integral/tests/test_integral.c task5_integral/libintegral.a
	gcc -Itask5_integral/include -Ltask5_integral -lintegral task5_integral/tests/test_integral.c -lm -o $@
