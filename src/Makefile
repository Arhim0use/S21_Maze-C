CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -std=c11 `pkg-config --cflags check`  
LDFLAGS     = -lpthread -lm $(shell pkg-config --libs check)

# Используйте pkg-config для получения флагов для библиотеки Check
SRC         = $(wildcard */*.c)
OBJ         = $(patsubst %.c, %.o, ${SRC})
TARGET      = s21_maze.a
TEST        = test
FILE_TEST   = $(wildcard maze_unit_test/s21_*.c)
VG_FLAGS     = --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

all: clean maze_model

maze_model:
	$(CC) -Wall -Wextra ./ch_main.c ./s21_maze_model/maze_model.c \
	./s21_maze_generator/maze_generator.c ./C_Matrix/s21_matrix.c -o ./$(TEST) -lm && ./$(TEST)

$(TARGET): $(OBJ)
	@ $(AR) rcs $@ $^

%.o: */%.c
	@ $(CC) $(CFLAGS) -c $< -o $@

test: clean $(TARGET)
	@ $(CC) $(CFLAGS)  --coverage $(FILE_TEST) $(TARGET) -o $(TEST) $(LDFLAGS)
	@ ./$(TEST)

# gcov_report: test
# 	$(CC) --coverage $(CFLAGS) $(LDFLAGS) $(FILE_TEST) s21_matrix.a $(SRC) -o test $(CHECK)
# 	./test
# 	lcov -t "test" -o tests.info -c -d .
# 	genhtml -o coverage tests.info
# 	open coverage/index.html

clean:
	@ find . -type f -name '*.out' | xargs -I {} sh -c 'rm -f {}'
	@ find . -type f -name '*.o' | xargs -I {} sh -c 'echo "File deleted {} " && rm -f {}'
	@ find . -type f -name '*.gcno' -or -name '*.gcda' -or -name '$(TARGET).info' \
				| xargs -I {} sh -c 'echo "File deleted {} " && rm -f {}'
	@ rm -f *.gcda *.gcno *.info *.out $(TEST)
	@ rm -rf coverage test.dSYM

# valgrind_check: test
# 	CK_FORK=no valgrind  $(VG_FLAGS) ./$(TARGET)

# leak: test
# 	CK_FORK=no leaks -atExit -- ./$(TARGET) | grep leaks

clang:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -n */*.c 
	clang-format -style=Google -i */*.c 


docker:
	@echo "+-------------------+"
	@echo "|    DOCKER_RUN     |"
	@echo "+-------------------+"
	@sh ../build/run.sh

valgrind: test
	@echo "+-------------------+"
	@echo "|   VALGRIND_LEAK   |"
	@echo "+-------------------+"
	@CK_FORK=no valgrind  $(VG_FLAGS) ./$(TEST)


