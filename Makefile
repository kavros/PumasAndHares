CXX ?=g++

# paths #
CPPUNITLDFLAGS=-lcppunit -Isrc -Itest
SRC_PATH=src/core
BUILD_PATH=build
BIN_PATH = $(BUILD_PATH)/bin
OUTPUTS =./data/outputs/*
# executables #
BIN_NAME=pumasAndHares

# extensions #
SRC_EXT=cpp
SOURCES=$(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' -not -name main.cpp | sort -k 1nr| cut -f2-)
OBJECTS=$(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
	
# flags #
COMPILE_FLAGS=-std=c++11 -Wall -Wextra -g -std=c++0x -O3

INCLUDES= -I include/ -I /usr/local/include

.PHONY: default_target
default_target: release

.PHONY:docs
docs:
	doxygen Doxyfile

.PHONY: clean
clean:
	@echo "Deleting build directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)
	@echo "Deleting outputs"
	#@$(RM) $(OUTPUTS)

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
	
$(BUILD_PATH)/%.o: src/cppunit_tests/%.cpp\
					$(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

	
$(BUILD_PATH)/cppunit_test_driver.o:src/cppunit_tests/cppunit_test_driver.cc
	$(CXX) $(COMPILE_FLAGS) -c src/cppunit_tests/cppunit_test_driver.cc $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

$(BIN_PATH)/%: $(BUILD_PATH)/cppunit_test_driver.o\
				$(OBJECTS)\
				$(BUILD_PATH)/%.o
	$(CXX) $(COMPILE_FLAGS) $^ $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

.PHONY: tests
tests:	$(BIN_PATH)/CmdParserUnitTest \
	$(BIN_PATH)/ConfigurationGeneratorUnitTest \
	$(BIN_PATH)/ConfigurationParserUnitTest\
	$(BIN_PATH)/LandscapeGeneratorUnitTest\
	$(BIN_PATH)/LandscapeParserUnitTest\
	$(BIN_PATH)/LandscapeUnitTest\
	$(BIN_PATH)/OutputGeneratorUnitTest

.PHONY: run_unit_tests
run_unit_tests:
	./$(BIN_PATH)/CmdParserUnitTest 
	./$(BIN_PATH)/ConfigurationGeneratorUnitTest 
	./$(BIN_PATH)/ConfigurationParserUnitTest
	./$(BIN_PATH)/LandscapeGeneratorUnitTest
	./$(BIN_PATH)/LandscapeParserUnitTest
	./$(BIN_PATH)/LandscapeUnitTest
	./$(BIN_PATH)/OutputGeneratorUnitTest

.PHONY: run
run:
	./$(BIN_PATH)/pumasAndHares -i data/landscapes/crete3.dat -c data/configs/config.json -p output
	
$(BIN_PATH)/landscapeGeneratorMain: src/generators/LandscapeGeneratorMain.cpp \
				    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^ -o $@
	
$(BIN_PATH)/configurationGeneratorMain: src/generators/ConfigurationGeneratorMain.cpp \
			    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^ -o $@
	

$(BIN_PATH)/$(BIN_NAME): $(OBJECTS) src/core/main.cpp
	$(CXX) $(COMPILE_FLAGS) $^  -o $@

# Creation of the executable
#$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
#	@echo "Linking: $@"
#	$(CXX) $(OBJECTS) -o $@

#land

# Creation of the object files
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(COMPILE_FLAGS)  -c $< -o $@


