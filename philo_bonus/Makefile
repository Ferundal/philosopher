# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh		#for systems where SHELL variable can be inherited from environment

.SUFFIXES:			#no suffix rules are used

LIBS=

LIBS_DIR=			${dir ${LIBS}}

LIBS_INC_F=			-L ${dir ${LIBS}} -l${patsubst lib%.a, %, ${notdir ${LIBS}}}

LIBS_INC=			${foreach LIBS, ${LIBS}, ${LIBS_INC_F}}

LIBS_HEADERS=		${patsubst %.a, %.h, ${LIBS}}

HEADERS_PHILO=		headers/philo.h

HEADERS_B_PHILO=

HEADERS=			${LIBS_HEADERS} ${HEADERS_PHILO}

ifdef COMPILE_BONUS
HEADERS:=			${HEADERS} ${HEADERS_B_PHILO}
endif

INC_HEADERS_FORMAT=	-I ${dir ${HEADERS}}

INC_HEADERS_DIR=	${foreach HEADERS, ${HEADERS}, ${INC_HEADERS_FORMAT}}

SRCS_C=				src/main.c \
					src/philo_errors.c \
					src/ft_isdigit.c \
					src/philo.c \
					src/philo_output.c \
					src/philo_usleep.c \
					src/ft_atoi.c \
					src/philo_init.c \
					src/philo_simulation.c \
					src/philo_overseer.c \
					src/philo_free.c \
					src/philo_acc_mutexes.c \
					src/philo_start.c \

SRCS_C_BONUS=

ifdef COMPILE_BONUS
SRCS_C:=			${SRCS_C} ${SRCS_C_BONUS}
endif

OBJS_C_BONUS=		${SRCS_C_BONUS:.s=.o}

OBJS_C=				${SRCS_C:src/%.c=obj/%.o}

NAME=				philo

CC=					cc -pthread
RM=					rm -f
LD=					ld -pthread

ALL_CFLAGS=			-Wall -Wextra -Werror -g ${INC_HEADERDIR} ${CFLAGS}
ALL_LDFLAGS=		-g ${LDFLAGS}

NORM=				norminette ${NORMO}

.PHONY:				all clean fclean re bonus libs_make libs_clean

all:				libs_make ${NAME}

libs_make:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} bonus}

obj/%.o:			src/%.c ${HEADERS}
					${CC} ${ALL_CFLAGS} ${INC_HEADERS_DIR} -c ${<} -o ${<:src/%.c=obj/%.o}

${NAME}:			${OBJS_C} ${LIBS}
					${CC} ${ALL_LDFLAGS} ${OBJS_C} ${LIBS_INC} ${LIBS_EXT} -o ${NAME}

bonus:
					${MAKE} COMPILE_BONUS=1 all

#$(INSTALL_PROGRAM)=	${TEST_NAME} $(DESTDIR)$(bindir)/foo	#where executeable shoud be placed
#$(INSTALL_DATA)=	${NAME} $(DESTDIR)$(libdir)/libfoo.a		#where libs shoud be placed



clean:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} clean}
					${RM} ${OBJS_C} ${OBJS_C_BONUS}

fclean:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} fclean}
					${RM} ${OBJS_C} ${OBJS_C_BONUS}
					${RM} ${NAME}

norm:		
					${NORM} ${LIBS_DIR} *.c *.h

re:					fclean all

# .DELETE_ON_ERROR