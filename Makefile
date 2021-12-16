# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 00:29:52 by tsomsa            #+#    #+#              #
#    Updated: 2021/12/16 17:14:16 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#Color
RED = \033[1;31m
BLUE = \033[1;34;47m
GREEN = \033[1;32m
RESET = \033[m

g_board = generate_fun_board.pl
f_board = fun_board.txt
x = 20
y = 20
dens = 5
files=main.c services/*.c
cflags = -Wall -Werror -Wextra
target = bsq

$(target) : $(objects)
		make -C utilities/
		make -C services/
		gcc -c main.c
		gcc $(cflags) -o $(target) *.o services/*.o utilities/*.o
		@echo "Compiled file: bsq"
		@echo ""		
all: compile

gen_board:
	@echo "${RED}Generating Fun Board follow by this rules...${RESET}"
	@echo "- width = ${x}\n- height = ${y}\n- Dens = ${dens}"
	@perl ${g_board} ${x} ${y} ${dens} > ${f_board} 
	@echo "${BLUE}=== Your ${f_board} File ===${RESET}"
	@cat ${f_board}
	@echo ""

compile:
	@gcc $(cflags) ${files} -o bsq.out
	@echo "Compiled file: bsq.out"
	@echo ""

execute:
	@echo "${GREEN}Executing your code...${RESET}"
	@./bsq.out

.PHONY: clean

clean:
	@rm -f *.o ${f_board}
	@echo "*.o has cleaned"
	@echo "${f_board} has cleaned"

fclean:
	@rm -rf *.o ${f_board} ${target}
	@echo "*.o has cleaned"
	@echo "${f_board} has cleaned"
	@echo "${target} has remove"
