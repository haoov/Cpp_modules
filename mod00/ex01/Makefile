#PROJECT
TARGET		=	PhoneBook
PROJDIR		=	$(realpath $(CURDIR))
SRCDIR		=	$(PROJDIR)/srcs
INCDIR		=	$(PROJDIR)/incs
OBJDIR		=	$(PROJDIR)/objs
DEPDIR		=	$(PROJDIR)/deps

#COMPILER
CC			=	g++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++98
INCLUDE		=	-I $(INCDIR)

#FILES
SRCS		=	$(shell find $(SRCDIR)/ -type f -name *.cpp)
OBJS		=	$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRCS:.cpp=.o))
DEPS		=	$(patsubst $(SRCDIR)/%,$(DEPDIR)/%,$(SRCS:.cpp=.d))

#RULES
all : $(TARGET)

$(TARGET) : $(OBJS)
	@$(CC) $(CCFLAGS) $(INCLUDE) $^ -o $@
	@printf "Linking $(notdir $@)\n"

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@mkdir -p $(patsubst $(OBJDIR)/%,$(DEPDIR)/%,$(dir $@))
	@$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@ -MMD -MF $(patsubst $(OBJDIR)/%,$(DEPDIR)/%,$(@:.d=.o))
	@printf "Building $(notdir $@)\n"

clean :
	@rm -rf $(DEPDIR) $(OBJDIR)
	@printf "Cleaning $(notdir $(OBJS))\n"

fclean : clean
	@rm -rf $(TARGET)
	@printf "Cleaning $(OBJDIR) $(DEPDIR)\n"

re : fclean all

.PHONY : all clean fclean re