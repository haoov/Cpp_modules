#PROJECT
TARGET		=	sed2.0
SRCDIR		=	$(CURDIR)/srcs
OBJDIR		=	$(CURDIR)/objs
DEPDIR		=	$(CURDIR)/deps
INCDIR		=	$(CURDIR)/incs

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
	@printf "Linking $(notdir $@)\n"

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@mkdir -p $(patsubst $(OBJDIR)/%,$(DEPDIR)/%,$(dir $@))
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -MMD -MF $(patsubst $(OBJDIR)/%,$(DEPDIR)/%,$(@:.o=.d))
	@printf "Building $(notdir $@)\n"

-include $(DEPS)

clean :
	rm -rf $(OBJDIR)
	rm -rf $(DEPDIR)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re