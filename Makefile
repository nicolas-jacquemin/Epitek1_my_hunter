##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## My-Hunter Makefile
##

src_path = src/

SRC = $(src_path)SpriteGest/background.c \
	  $(src_path)window/window.c \
	  $(src_path)event/event_handler.c \
	  $(src_path)drawing/game_window.c \
	  $(src_path)drawing/title_window.c \
	  $(src_path)SpriteGest/pnj.c \
	  $(src_path)SpriteGest/pnj_random.c \
	  $(src_path)SpriteGest/pnj_spawn_tools.c \
	  $(src_path)SpriteGest/pnj_hitbox.c \
	  $(src_path)SpriteGest/window_title.c \
	  $(src_path)clock.c \
	  $(src_path)sound.c \
	  $(src_path)game_state.c \
	  $(src_path)warpzone/warp.c \
	  $(src_path)warpzone/warp_0to400.c \
	  $(src_path)warpzone/warp_400to1080.c

NAME = my_hunter

lib_path = lib/my/

Lib_SRC = 	$(lib_path)my_strncmp.c \
			$(lib_path)my_putstr.c \
			$(lib_path)my_putchar.c \
			$(lib_path)my_strlen.c \
			$(lib_path)itos.c \

Lib_OBJ = 	$(Lib_SRC:.c=.o)

Lib_NAME = 	libmy

lib_csfml = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

lib_flags = -L. -lmy -Iinclude $(lib_csfml)

include = -I$(src_path)/include/.

cpl_fl = -Wall -Wextra

default:
		@make all --no-print-directory -s

extract_assets:
		@cd res && tar -xf assets.tgz
		printf "\033[1;38m"
		echo "[*] assets extracted"
		printf "\033[0m"

compress_assets:
		@cd res && touch assets.tgz && rm assets.tgz && tar -czf assets.tgz *
		printf "\033[1;38m"
		echo "[*] assets compressed"
		printf "\033[0m"

lib_my:		$(Lib_OBJ)
		printf "\033[1;35m"
		gcc -c $(Lib_SRC)
		ar rc $(Lib_NAME).a $(Lib_OBJ)
		echo "[*] libmy compiled"
		printf "\033[0m"

all:
		@make $(NAME) --no-print-directory -s

.ONESHELL:
$(NAME): 	$(SRC)
		printf "\033[1;33m--- KFC Hunter [my_hunter EPITECH 2022 Project] "
		printf "\033[1;33m---\033[0m\n"
		make build --no-print-directory -s
		if [ $$? -eq 0 ]; then
			printf "\033[1;32m"
			echo "[*] $(NAME) compiled"
			printf "\033[0m"
		else
			printf "\033[1;31m"
			echo "[!] $(NAME) compilation failed"
			printf "\033[0m"
		fi
		printf "\033[0m--- END OF COMPILATION ---\n"

build:
	@make lib_my
	@make extract_assets
	@gcc $(SRC) $(src_path)main.c $(lib_flags) $(include) $(cpl_fl) -o $(NAME)

clean:
		@printf "\033[1;34m[*] Cleaning libmy bin files\033[0m\n"
		@rm -f $(wildcard lib/my/*.o)
		@rm -f $(wildcard *.o)
		@make lib_fclean -s --no-print-directory

lib_fclean:
		@printf "\033[1;30m[*] Cleaning libmy.a\033[0m\n"
		@rm -f ./$(Lib_NAME).a

fclean:
		@printf "\033[1;37m[*] Cleaning $(NAME)\033[0m\n"
		@make clean -s --no-print-directory
		@printf "\033[1;38m[*] Cleaning assets files\033[0m\n"
		@rm -f $(wildcard res/*.png)
		@rm -f $(wildcard res/*.ogg)
		@rm -f $(wildcard res/*.ttf)
		@rm -f $(wildcard res/*.otf)
		@rm -f $(NAME)

re: fclean
		@printf "\033[1;36m[*] Force Recompilation [*]\033[0m\n"
		@make $(NAME) -s --no-print-directory

unit_tests: clean_tests
		@printf "\033[1;33m--- KFC Hunter [my_hunter EPITECH 2022 Project] "
		@printf "\033[1;33m---\033[0m\n"
		@printf "\033[1;32m[*] Unit Tests Compilation\033[0m\n"
		@make re
		@make extract_assets
		@gcc -o test $(SRC) tests/*.c $(lib) $(include) -lcriterion --coverage

tests_run: unit_tests
		@printf "\033[1;32m[*] Unit Tests Execution\033[0m\n"
		@./test > testlog
		@rm testlog

coverage: tests_run
		@printf "\033[1;32m[*] Unit Tests Coverage\033[0m\n"
		@gcovr --exclude tests/ --exclude lib/my/
		@make clean_tests

clean_tests:
		@printf "\033[1;34m[*] Cleaning Unit Tests\033[0m\n"
		@rm -f test
		@rm -f *.gc*
