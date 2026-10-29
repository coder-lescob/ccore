CC := gcc

BUILD := target
SRC   := src
TEST  := tests

# the headers of the library
LIB_HEADERS := includes

# inside of the build/ there are multiple builds debug, release and test
# test is for the tests and does not include the library and will take the dev target lib
DEV_BUILD := $(BUILD)/debug
REL_BUILD := $(BUILD)/release
TEST_BUILD := $(BUILD)/test

# get the sources and the objects
LIB_SRC  := $(wildcard $(SRC)/*.c)
TEST_SRC := $(wildcard $(TEST)/*.c)
DEV_OBJ  := $(patsubst %.c,$(DEV_BUILD)/%.o,$(LIB_SRC))
REL_OBJ  := $(patsubst %.c,$(REL_BUILD)/%.o,$(LIB_SRC))
TEST_OBJ := $(patsubst %.c,$(TEST_BUILD)/%.o,$(TEST_SRC))

# the targets based on release or dev build
DEV_TARGET := $(DEV_BUILD)/libccore.so
REL_TARGET := $(REL_BUILD)/libccore.so
TEST_TARGET := $(TEST_BUILD)/ccore_tests

# -fPIC for position independent code
# -MD and -MMD to generate depedency files
LIB_OFLAGS := -nostdlib -fno-builtin -fPIC -MMD -MD -I"$(LIB_HEADERS)" -I"$(SRC)"

# specific flags
DG_OFLAGS := -ggdb $(LIB_OFLAGS)
RL_OFLAGS := $(LIB_OFLAGS)
TEST_OFLAGS := -nostdlib -MMD -MD -I"$(LIB_HEADERS)" -fno-stack-protector -fno-builtin
TEST_LDFLAGS := -Wl,-rpath,$(dir $(DEV_TARGET))

# make sure depedency files make the code regenerate
-include $(DEV_OBJ:.o=.d)
-include $(REL_OBJ:.o=.d)
-include $(TEST_OBJ:.o:.d)

# build an object for the DEV build
$(DEV_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) -c $(DG_OFLAGS) $< -o $@

# build an object for the release build
$(REL_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) -c $(RL_OFLAGS) $< -o $@

# build an object for the test build
$(TEST_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) -c $(TEST_OFLAGS) $< -o $@

# build the dev target
$(DEV_TARGET): $(DEV_OBJ)
	@echo CC $@
	@$(CC) -shared $(DG_OFLAGS) $(DEV_OBJ) -o $(DEV_TARGET)

# build the release target
$(REL_TARGET): $(REL_OBJ)
	@echo CC $@
	@$(CC) -shared $(RL_OFLAGS) $(REL_OBJ) -o $(REL_TARGET)

$(TEST_TARGET): build_dev $(TEST_OBJ)
	@mkdir -p $(dir $@)
	@echo CC $@
	@$(CC) $(TEST_OFLAGS) $(TEST_OBJ) -o $@ -L$(dir $(DEV_TARGET)) -l$(patsubst $(DEV_BUILD)/lib%.so,%,$(DEV_TARGET)) $(TEST_LDFLAGS)

build_dev: $(DEV_TARGET)
	@echo dev target compiled

build_release: $(REL_TARGET)
	@echo release target compiled

test: $(TEST_TARGET)
	@echo test compiled
	@$(TEST_TARGET)

clean:
	@rm -r $(BUILD)
	@echo CLEAN
