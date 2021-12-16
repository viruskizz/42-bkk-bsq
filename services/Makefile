# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 16:33:42 by npiya-is          #+#    #+#              #
#    Updated: 2021/12/16 17:40:58 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = *.c

name = libservices.a

$(name):$(src) 
	gcc -c $(src)
	ar rc $(name) *.o
	mv $(name) ../lib/my/
	rm -f *.o

all:	$(name)

clean:
	rm -f *.o
	rm -f *~

fclean:
	rm -f $(name) *.o

re: fclean all
