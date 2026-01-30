#!-------NAME-------!

SERVER = server
CLIENT = client

#!-------COLORS-------!

GREEN = \033[0;32m
ORANGE = \033[38;5;208m
YELLOW = \033[0;33m
PINK = \033[38;5;205m
RESET = \033[0m

#!-------CC AND FLAGS-------!

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
DEPFLAGS = -MMD -MP
AR = ar rcs
RM = rm -rf

#!-------DIRECTORIES-------!

SRC_DIR = src
OBJ_DIR = obj

#!-------SOURCE FILES-------!

CLIENT_SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, client))
SERVER_SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, server))

#!-------OBJECT FILES-------!

CLIENT_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CLIENT_SRC))
SERVER_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SERVER_SRC))

#!-------DEPENDENCIES-------!

DEPS = $(CLIENT_OBJS:.o=.d) $(SERVER_OBJS:.o=.d)

#!-------RULES------!

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CLIENT_OBJS) -o $@
	@echo -e "$(GREEN) $@ compiled successfully!$(RESET)"

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(SERVER_OBJS) -o $@
	@echo -e "$(GREEN) $@ compiled successfully!$(RESET)"

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) $(DEPFLAGS) -c $< -o $@

#!-------CLEANING-------!

clean:
	@$(RM) $(OBJ_DIR)
	@echo -e "$(ORANGE)Files cleaned!$(RESET)"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@echo -e "$(ORANGE)Full clean completed!$(RESET)"

re: fclean all
	@echo -e "$(PINK)Rebuilt compleated$(RESET)"

.PHONY: all clean fclean re
