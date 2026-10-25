# C++ compiler
CXX = g++

# use C++11 standard and display common compiler warnings
CXXFLAGS = -std=c++11 -Wall -Wextra

# Name of the finished executable
TARGET = hw3

# every C++ source file required by the program
SOURCES = main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp

# create the object-file required by program
OBJECTS = $(SOURCES:.cpp=.o)

# the default rule runs when make is entered
all: $(TARGET)

# link all object files to create final executable, used semicolon because github converted my tabs into 2 spaces
$(TARGET): $(OBJECTS) ; $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# compile each .cpp source file into its matching .o object file
%.o: %.cpp ; $(CXX) $(CXXFLAGS) -c $< -o $@

#remove generated object files and the excutable. source code and input files not deleted
clean: ; rm -f $(OBJECTS) $(TARGET)
