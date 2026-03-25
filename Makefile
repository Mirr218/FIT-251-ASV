.PHONY: clear check_fmt fmt test

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find . -name "*.c" -o -name "*.h"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find . -name "*.c" -o -name "*.h"`

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
	gcc -g -o $@ $< $*.a -lm

%.a: %.o
	ar rc $@ $<

%.o: %.c
	gcc -g -c $< -o $@

llist_test: list_test.o list.a
