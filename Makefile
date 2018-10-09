CXX ?=g++

# paths #
SRC_PATH=src
BUILD_PATH=build
BIN_PATH = $(BUILD_PATH)/bin

# executables #
BIN_NAME=generate_landscape

# extensions #
SRC_EXT=cpp
SOURCES=$(shell find $(SRC_PATH) -name '*.$(SRC_EXT)'| sort -k 1nr| cut -f2-)
OBJECTS=$(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)

# flags #
COMPILE_FLAGS=-std=c++11 -Wall -Wextra -g
INCLUDES= -I include/ -I /usr/local/include

.PHONY: default_target
default_target: release


.PHONY: clean
clean:
	@echo "Deleting build directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

.PHONY: release
release: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)

release: dirs
	@$(MAKE) all

# Checks the executable and symlinks to the output
.PHONY: all
all: $(BIN_PATH)/$(BIN_NAME)
	@echo "Making symlink: $(BIN_NAME) -> $<"
	@$(RM) $(BIN_NAME)
	#@ln -s $(BIN_PATH)/$(BIN_NAME) $(BIN_NAME)

# Creation of the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@

# Creation of the object files
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES)   -c $< -o $@


