CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = hw3

SOURCES = main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) ; $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp ; $(CXX) $(CXXFLAGS) -c $< -o $@

clean: ; rm -f $(OBJECTS) $(TARGET)
