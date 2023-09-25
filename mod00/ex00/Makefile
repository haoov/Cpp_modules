#PROJECT
TARGET		=	megaphone

#COMPILER
CC			=	g++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++98

#FILES
SRCS		=	$(shell find . -type f -name *.cpp)
OBJS		=	$(SRCS:.cpp=.o)

#RULES
all			: $(TARGET)

$(TARGET)	: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o			: %.cpp
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

clean		:
	rm -rf $(OBJS)

fclean		: clean
	rm -rf $(TARGET)

re			: fclean all

.PHONY		: all clean fclean re