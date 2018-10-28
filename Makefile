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
COMPILE_FLAGS=-std=c++11 -Wall -Wextra -g -std=c++0x

INCLUDES= -I include/ -I /usr/local/include

.PHONY: default_target
default_target: release


.PHONY: clean
clean:
	@echo "Deleting build directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)
	@echo "Deleting outputs"
	@$(RM) $(OUTPUTS)

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
	$(BIN_PATH)/landscapeParserTest\
	
.PHONY: tests
tests:$(BIN_PATH)/outputGenerator-cppunitest
	./$<

$(BUILD_PATH)/OutputGeneratorUnitTest.o: src/cppunit_tests/OutputGeneratorUnitTest.cpp\
					$(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) -c src/cppunit_tests/OutputGeneratorUnitTest.cpp $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

$(BUILD_PATH)/cppunit_test_driver.o:src/cppunit_tests/cppunit_test_driver.cc
	$(CXX) $(COMPILE_FLAGS) -c src/cppunit_tests/cppunit_test_driver.cc $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

$(BIN_PATH)/outputGenerator-cppunitest:$(BUILD_PATH)/cppunit_test_driver.o\
				$(OBJECTS)\
				$(BUILD_PATH)/OutputGeneratorUnitTest.o
	$(CXX) $(COMPILE_FLAGS) $^ $(CPPUNITLDFLAGS) $(INCLUDES) -o $@



$(BIN_PATH)/landscapeGeneratorMain: src/tests/LandscapeGeneratorMain.cpp \
				    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^ -o $@
	
$(BIN_PATH)/cmdParserTest: src/tests/CmdParserTest.cpp \
			    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS)  $^ -o $@

$(BIN_PATH)/configurationGeneratorMain: src/tests/ConfigurationGeneratorMain.cpp \
			    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^ -o $@

$(BIN_PATH)/configurationParserTest: src/tests/ConfigurationParserTest.cpp \
			    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^ -o $@


$(BIN_PATH)/landscapeParserTest: src/tests/LandscapeParserTest.cpp \
			    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^ -o $@
	
	

$(BIN_PATH)/landscapeSimulationTest: src/tests/LandscapeSimulationTest.cpp \
			    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^  -o $@


$(BIN_PATH)/landscapeValidatorTest: src/tests/LandscapeValidatorTest.cpp \
			    $(OBJECTS)
	$(CXX) $(COMPILE_FLAGS) $^ -o $@


$(BIN_PATH)/outpoutGeneratorTest: src/tests/OutputGeneratorTest.cpp \
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


