CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -std=c11  
LDFLAGS		=	`pkg-config --cflags --libs check` -lcheck -lpthread -lm  

CHECK		=	$(shell pkg-config --cflags --libs check)
FS			=	-fsanitize=address -g

SRC			=	$(wildcard s21_*.c)
OBJ			=	$(patsubst %.c,%.o, ${SRC})
TARGET 		= 	s21_matrix.a
TEST		=	test
FILE_TEST	=	$(wildcard unit_test/s21_*.c)
VG_FLAGS	=	--vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

all: clean s21_matrix.a

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) rcs $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $<

test: clean s21_matrix.a
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage $(FILE_TEST) s21_matrix.a -o $@ $(CHECK)
	./$(TEST)

gcov_report: test
	$(CC) --coverage $(CFLAGS) $(LDFLAGS) $(FILE_TEST) s21_matrix.a $(SRC) -o test $(CHECK)
	./test
	lcov -t "test" -o tests.info -c -d .
	genhtml -o coverage tests.info
	open coverage/index.html

clean:
	rm -f *.a *.o *.gcda *.gcno *.info *.out test
	rm -rf coverage test.dSYM

valgrind_check: test
	CK_FORK=no valgrind  $(VG_FLAGS) ./$(TARGET)

leak: test
	CK_FORK=no leaks -atExit -- ./$(TARGET) | grep leaks

clang:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -n */*.c 
	clang-format -style=Google -i */*.c 
