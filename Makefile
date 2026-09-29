CC = clang

SRC_DIR := source
INC_DIR := include
BIN_DIR := binary
LIB_DIR := library

BRIKCRASH := brikcrash
TERRENITY := terrenity

ifeq ($(CC), clang)
CFLAGS := -std=gnu99 -O3 -Werror -Wall -Wextra -Wpedantic -Wno-unused-command-line-argument
LIB_FLAGS := -Wl,--library-path=$(LIB_DIR),--library=$(TERRENITY),-rpath=$(LIB_DIR)
else ifeq ($(CC), gcc)
CFLAGS := -std=gnu99 -O3 -Werror -Wall -Wextra -Wpedantic
LIB_FLAGS := -L$(LIB_DIR) -l$(TERRENITY) -Wl,-rpath=$(LIB_DIR)
else
$(error unsupported compiler : $(CC))
endif

SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/background/*.c) $(wildcard $(SRC_DIR)/brick/*.c) $(wildcard $(SRC_DIR)/paddle/*.c) $(wildcard $(SRC_DIR)/ball/*.c) $(wildcard $(SRC_DIR)/keyboard/*.c)
HDR_FILES := $(wildcard $(INC_DIR)/*.h) $(wildcard $(INC_DIR)/background/*.h) $(wildcard $(INC_DIR)/brick/*.h) $(wildcard $(INC_DIR)/paddle/*.h) $(wildcard $(INC_DIR)/ball/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC_FILES))

INCLUDE_FLAGS := -I$(INC_DIR)

POINTER_SYM := "\e[91m->\e[0m"

$(BRIKCRASH) : $(BIN_DIR) $(OBJ_FILES) $(HDR_FILES)
	@/usr/bin/echo -e $(POINTER_SYM) "\e[96mlinking modules into" $@ "\e[0m"
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LIB_FLAGS)
	@/usr/bin/echo -e $(POINTER_SYM) "\e[93mstrip" $@ "\e[0m"
	@strip $@

$(BIN_DIR) :
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BIN_DIR)/background
	@mkdir -p $(BIN_DIR)/ball
	@mkdir -p $(BIN_DIR)/brick
	@mkdir -p $(BIN_DIR)/paddle
	@mkdir -p $(BIN_DIR)/keyboard

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/%.h
	@/usr/bin/echo -e $(POINTER_SYM) "\e[93mcompiling module" $< "\e[0m"
	$(CC) -c $(CFLAGS) $(LIB_FLAGS) $(INCLUDE_FLAGS) -o $@ $<

clean :
	rm $(wildcard $(BIN_DIR)/*.o)
	rm $(wildcard $(BIN_DIR)/background/*.o)
	rm $(wildcard $(BIN_DIR)/ball/*.o)
	rm $(wildcard $(BIN_DIR)/brick/*.o)
	rm $(wildcard $(BIN_DIR)/paddle/*.o)
	rm $(wildcard $(BIN_DIR)/keyboard/*.o)
	rm $(wildcard $(BRIKCRASH))

clear : clean
