CXX ?=g++

# paths #
SRC_PATH=src/core
BUILD_PATH=build
BIN_PATH = $(BUILD_PATH)/bin

# executables #
BIN_NAME=pumasAndHares

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
all:	$(BIN_PATH)/$(BIN_NAME) \
	$(BIN_PATH)/landscapeGeneratorMain\
	$(BIN_PATH)/configurationGeneratorMain\
	$(BIN_PATH)/cmdParserTest\
	$(BIN_PATH)/configurationGeneratorMain\
	$(BIN_PATH)/configurationParserTest\
	$(BIN_PATH)/landscapeSimulationTest\
	$(BIN_PATH)/landscapeValidatorTest\
	$(BIN_PATH)/outpoutGeneratorTest\
	$(BIN_PATH)/landscapeParserTest
	
	

$(BIN_PATH)/landscapeGeneratorMain: src/tests/LandscapeGeneratorMain.cpp \
				    src/core/LandscapeGenerator.cpp
	$(CXX)  src/core/LandscapeGenerator.cpp $< -o $@
	
$(BIN_PATH)/cmdParserTest: src/tests/CmdParserTest.cpp \
			    src/core/CmdParser.cpp
	$(CXX)  $< -o $@

$(BIN_PATH)/configurationGeneratorMain: src/tests/ConfigurationGeneratorMain.cpp \
			    src/core/ConfigurationGenerator.cpp
	$(CXX)  $< -o $@

$(BIN_PATH)/configurationParserTest: src/tests/ConfigurationParserTest.cpp \
			    src/core/ConfigurationParser.cpp
	$(CXX)  $< -o $@


$(BIN_PATH)/landscapeParserTest: src/tests/LandscapeParserTest.cpp \
			    src/core/LandscapeParser.cpp
	$(CXX)  $< -o $@
	
	

$(BIN_PATH)/landscapeSimulationTest: src/tests/LandscapeSimulationTest.cpp \
			    src/core/LandscapeSimulation.cpp
	$(CXX)  $< -o $@


$(BIN_PATH)/landscapeValidatorTest: src/tests/LandscapeValidatorTest.cpp \
			    src/core/LandscapeValidator.cpp
	$(CXX)  $< -o $@


$(BIN_PATH)/outpoutGeneratorTest: src/tests/OutputGeneratorTest.cpp \
			    src/core/OutputGenerator.cpp
	$(CXX)  $< -o $@



# Creation of the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@

#land

# Creation of the object files
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES)   -c $< -o $@


