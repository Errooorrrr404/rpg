##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2018
## File description:
## Makefile
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

SRCNAMES	= 	  add_default_capacity_pkmn.c \
	  add_pkmn.c \
	  catch_str.c \
	  create.c \
	  create_menu.c \
	  csfml_tools.c \
	  define_basic_value_pkmn.c \
	  display.c \
	  display_stats.c \
	  event.c \
	  file_to_tab.c \
	  free.c \
	  game_rpg.c \
	  hit_boxes.c \
	  how_to_play.c \
	  how_to_play_state.c \
	  how_to_play_state_part_two.c \
	  init.c \
	  get_time.c \
	  init_game.c \
	  init_hit_box.c \
	  hit_box_labo.c \
	  main.c \
	  menu_rpg.c \
	  move_map.c \
	  my_hit_box.c \
	  random.c \
	  rpg.c \
	  manage_pnj.c \
	  define_color_type.c \
	  get_position_from_window.c \
	  concat_all_stat_value.c \
	  pkm_battle_random.c \
	  get_info.c \
	  utilities.c \
	  pkmn_battle_random_misc.c \
	  choose_capacity_battle.c \
	  add_pkmn_sound.c \
	  define_battle_struct.c \
	  cinematic_battle_wild.c \
	  free_battle_wild_random.c \
	  free_pkmn_struct.c \
	  set_pos_sprite_battle.c \
	  catch_pkmn.c

SRCS = $(addprefix src/, $(SRCNAMES))

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += #-Wall -Wextra

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(OBJS) -o $(NAME) -L./lib/ -lmy $(LDFLAGS) $(CSFML)

clean:
	$(RM) $(OBJS)

fclean: clean
	make fclean -C lib/
	$(RM) $(NAME)

debug: CFLAGS += -g
debug: re
	make debug -C lib/

re: fclean all