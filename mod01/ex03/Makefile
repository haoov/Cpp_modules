#PROJECT
TARGET		=	violence

#COMPILER
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

#FILES
SRCS		=	$(shell find . -type f -name '*'.cpp)
OBJS		=	$(SRCS:.cpp=.o)

#RULES
all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re