CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = main.exe

all: $(TARGET)

$(TARGET): main.cpp DynamicArray.h
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

run: $(TARGET)
	chcp.com 65001
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
