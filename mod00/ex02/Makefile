#PROJECT
TARGET		=	Recovery
PROJDIR		=	$(realpath $(CURDIR))

#COMPILER
CC			=	c++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++98
INCLUDE		=	-I $(PROJDIR)

#FILES
SRCS		=	./tests.cpp\
				./Account.cpp
OBJS		=	$(SRCS:.cpp=.o)

#RULES
all : $(TARGET)

$(TARGET) : $(OBJS)
	@$(CC) $(CCFLAGS) $(INCLUDE) $^ -o $@
	@printf "Linking $(notdir $@)\n"

%.o : %.cpp
	@$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@
	@printf "Building $(notdir $@)\n"

clean :
	@rm -f $(OBJS)
	@printf "Cleaning $(notdir $(OBJS))\n"

fclean : clean
	@rm -rf $(TARGET)
	@printf "Cleaning $(notdir $(TARGET))\n"

re : fclean all

.PHONY : all clean fclean re