CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))
TARGET = Eiffillum

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o $(TARGET)

.PHONY: all clean

