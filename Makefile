CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra

PKGS = raylib raylib-cpp
LDFLAGS = $(shell pkg-config --libs $(PKGS))

SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))

TARGET = Eiffillum

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o $(TARGET)

.PHONY: all clean

