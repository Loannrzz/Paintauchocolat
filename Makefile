##
## EPITECH PROJECT, 2023
## makefile
## File description:
## libmy
##

CFLAGS =

ifeq ($(DEBUG),yes)
    CFLAGS += -g3
endif

CPPFLAGS = -I./include

LIB = ./lib

SRC := $(wildcard $(shell find $(SRC_DIRS) -name '*.c'))

OBJ = $(SRC:.c=.o)

NAME = mysh

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) $(OBJ) -o $(NAME) -L$(LIB) -lmy

clean:
	make clean -C $(LIB)
	$(RM) $(OBJ)
	$(RM) $(T_NAME)

fclean: clean
	make fclean -C $(LIB)
	$(RM) $(NAME)

re: fclean all


get_file_size = $(shell du -m --apparent-size $1 | awk '{printf "%.1f", $$1}')
get_file_owner = $(shell stat -c %U $1)
get_file_count_src = $(shell expr $(shell find ./src -type f | wc -l) / 2)
get_file_count_lib = $(shell expr $(shell find ./lib/my -type f | wc -l) / 2)
get_file_count_include = $(shell find ./include -type f | wc -l)
get_file_count_bonus = $(shell find ./bonus -type f | wc -l)
get_date_compilation = $(shell date +"%Y-%m-%d %H:%M:%S")
get_build_time = $(shell expr $(shell date +%s) - $(shell stat -c %W $(NAME)))
get_os_info = $(shell uname -a)
get_cpu_arch = $(shell uname -m)
get_compilation_option = $(CFLAGS)
get_compilation_command = $(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) -L$(LIB) -lmy
binary_size = $$(du -h $(NAME) | cut -f1)
get_line_of_code = $(shell find ./src ./lib/my '*.c' -exec cat {} \; | wc -l)
get_warning = $(shell cat $(SRC) | grep -i warning | wc -l)
get_error = $(shell cat $(SRC) | grep -i error | wc -l)
get_note = $(shell expr $(shell cat $(SRC) | grep -i warning | wc -l) \
 + $(shell cat $(SRC) | grep -i error | wc -l))
get_percent = $(shell expr $(shell cat $(SRC) | grep -i warning | wc -l) \
+ $(shell cat $(SRC) | grep -i error | wc -l) \* 100 / \
$(shell find ./src -type f | wc -l))
get_file_count_test = $(shell find ./tests -type f | wc -l)

debug: re
	@make fclean -C $(LIB)
	@$(RM) $(OBJ)
	@echo " "
	@echo "      ____  _____ ____  _   _  ____     __  __  ___  ____   ______"
	@echo "     |  _ \| ____| __ )| | | |/ ___|   |  \/  |/ _ \|  _ \ | ____|"
	@echo "     | | | |  _| |  _ \| | | | |  _    | |\/| | | | | | | ||  _|  "
	@echo "     | |_| | |___| |_) | |_| | |_| |   | |  | | |_| | |_| || |___ "
	@echo "     |____/|_____|____/ \___/ \____|   |_|  |_|\___/|____/ |_____|"
	@echo " "
	@echo " ┏━━━━━━━━━DEBUG MODE━━━━━━━━"
	@echo " ╞═ - Name project        : " $(NAME)
	@echo " ╞═ - File size           : " $(call get_file_size, $(NAME))"Mo"
	@echo " ╞═ - File owner          : " $(call get_file_owner, $(NAME))
	@echo " ╞═ - File count src      : " $(call get_file_count_src)
	@echo " ╞═ - File count lib      : " $(call get_file_count_lib)
	@echo " ╞═ - File count include  : " $(call get_file_count_include)
	@echo " ╞═ - File count bonus    : " $(call get_file_count_bonus)
	@echo " ╞═ - File count test     : " $(call get_file_count_test)
	@echo " ╞═ - Date compilation    : " $(call get_date_compilation)
	@echo " ╞═ - Build time          : " $(call get_build_time) "seconds"
	@echo " ╞═ - OS info             : " $(call get_os_info)
	@echo " ╞═ - CPU info            : " $(call get_cpu_arch)
	@echo " ╞═ - Compilation option  : " $(call get_compilation_option)
	@echo " ╞═ - Compilation command : " $(call get_compilation_command)
	@echo " ╞═ - Binary size         : " $(call binary_size)
	@echo " ╞═ - Line of code        : " $(call get_line_of_code)
	@echo " ╞═ - Warning             : " $(call get_warning)
	@echo " ╞═ - Error               : " $(call get_error)
	@echo " ╞═ - Note                : " $(call get_note)
	@echo " ╞═ - Percent error       : " $(call get_percent) "%"
	@echo " ┗━━━━━━━━━DEBUG MODE━━━━━━━━"
	@echo " "

valgrind: fclean $(OBJ)
	make -C $(LIB)
	$(CC) $(OBJ) -o $(NAME) -L$(LIB) -lmy -g3
	valgrind ./$(NAME)

get_major_count = $(shell grep -o -i 'MAJOR' coding-style-reports.log | wc -l)
get_minor_count = $(shell grep -o -i 'MINOR' coding-style-reports.log | wc -l)
get_info_count = $(shell grep -o -i 'INFO' coding-style-reports.log | wc -l)
get_line_cs = $(shell cat coding-style-reports.log | wc -l)

cs: fclean
	@./pretty-style.sh
	@echo " "
	@echo '      ____          _ _               ____  _         _        '
	@echo '     / ___|___   __| (_)_ __   __ _  / ___|| |_ _   _| | ___   '
	@echo '    | |   / _ \ / _  | |  _ \ / _  | \___ \| __| | | | |/ _ \  '
	@echo '    | |__| (_) | (_| | | | | | (_| |  ___) | |_| |_| | |  __/  '
	@echo '     \____\___/ \__,_|_|_| |_|\__, | |____/ \__|\__, |_|\___|  '
	@echo '                              |___/             |___/          '
	@echo " "
	@echo ' ┏━━━━━━CODING STYLE MODE━━━━━━━━━'
	@sed 's/^/ ╞═ - /' coding-style-reports.log | cat
	@echo ' ╞═ ━━━━━━CODING STYLE MODE━━━━━━━'
	@echo ' ╞═ - Nb Cs       :' $$(($(call get_line_cs)))
	@echo ' ╞═ - Nb MAJOR  ▲ :' $$(($(call get_major_count)))
	@echo ' ╞═ - Nb MINOR  ▼ :' $$(($(call get_minor_count)))
	@echo ' ╞═ - Nb INFO   ★ :' $$(($(call get_info_count)))
	@echo ' ┗━━━━━━━CODING STYLE MODE━━━━━━━'
	@echo " "

get_commit_count = $(shell git rev-list --count HEAD)
get_commit_hash = $(shell git rev-parse --short HEAD)
get_c_date = $(shell git log -1 --format=%cd --date=format:"%Y-%m-%d %H:%M:%S")
get_commit_author = $(shell git log -1 --format=%an)
get_commit_branch = $(shell git branch | grep \* | cut -d ' ' -f2)
get_nb_branch = $(shell git branch | wc -l)
get_nb_tag = $(shell git tag | wc -l)
get_nb_remote = $(shell git remote | wc -l)
get_nb_pull = $(shell git pull | wc -l)

push: fclean
	@echo "Ignoring files listed in .gitignore..."
	git add -u :/
	git commit -m "MAJ"
	git push
	@$(MAKE) commit

commit: fclean
	@echo " "
	@echo "    ____  _   _ ____  _   _     ____  _   _ ____  _   _   "
	@echo "   |  _ \| | | / ___|| | | |   |  _ \| | | / ___|| | | |  "
	@echo "   | |_) | | | \___ \| |_| |   | |_) | | | \___ \| |_| |  "
	@echo "   |  __/| |_| |___) |  _  |   |  __/| |_| |___) |  _  |  "
	@echo "   |_|    \___/|____/|_| |_|   |_|    \___/|____/|_| |_|  "
	@echo " "
	@echo ' ┏━━━━━━━━Push informations━━━━━━━'
	@echo ' ╞═ - Commit count    :' $(call get_commit_count)
	@echo ' ╞═ - Commit hash     :' $(call get_commit_hash)
	@echo ' ╞═ - Commit date     :' $(call get_c_date)
	@echo ' ╞═ - Commit author   :' $(call get_commit_author)
	@echo ' ╞═ - Commit branch   :' $(call get_commit_branch)
	@echo ' ╞═ - Nb branch       :' $(call get_nb_branch)
	@echo ' ╞═ - Nb tag          :' $(call get_nb_tag)
	@echo ' ╞═ - Nb remote       :' $(call get_nb_remote)
	@echo ' ╞═ - Nb pull         :' $(call get_nb_pull)
	@echo ' ┗━━━━━━Push informaations━━━━━━━━━'

pcc: fclean
	@$(MAKE) cs
	@$(MAKE) push
	@$(MAKE) commit
