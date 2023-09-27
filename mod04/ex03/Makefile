#PROJECT
TARGET		=	Materia
PROJDIR		=	$(realpath $(CURDIR))
SRCDIR		=	$(PROJDIR)/srcs
INCDIR		=	$(PROJDIR)/incs
OBJDIR		=	$(PROJDIR)/objs
DEPDIR		=	$(PROJDIR)/.deps

#COMPILER
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
INCLUDE		=	-I $(INCDIR)

#FILES
SRCS		=	$(shell find $(SRCDIR) -type f -name '*'.cpp)
OBJS		=	$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRCS:.cpp=.o))
DEPS		=	$(patsubst $(SRCDIR)/%,$(DEPDIR)/%,$(SRCS:.cpp=.d))

#RULES
all : $(TARGET)

$(TARGET) : $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@
	@echo Linking $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -MMD -MF $(patsubst $(OBJDIR)/%,$(DEPDIR)/%,$(@:.o=.d))
	@echo Building $(notdir $@)

-include $(DEPS)

clean :
	rm -rf $(OBJDIR)
	rm -rf $(DEPDIR)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re