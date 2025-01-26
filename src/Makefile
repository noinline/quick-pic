CXX ?= clang++
CXXFLAGS := \
			-Og \
			-Wall \
			-Wextra \
			-std=c++17 \
			-lSDL2 \
			-lSDL2_image \
			-Wno-unused-command-line-argument

CFMT ?= clang-format
OUT := quick-pic
OUT_DIR := build

SRCS := $(wildcard ./*.cpp)
HPPS := $(wildcard ./*.hpp ./*.h)
OBJS := $(SRCS:./%.cpp=$(OUT_DIR)/%.o)

$(OUT_DIR)/%.o: ./%.cpp 
	$(CXX) $(CXXFLAGS) $< -o $(CWD)$@ -c

MAKE_DIR := mkdir -p $(OUT_DIR)/

main:
	$(MAKE_DIR)
	$(MAKE) compile

compile: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o ./../$(OUT)

format:
	$(CFMT) -i $(SRCS) $(HPPS) $(HS)

install:
	install -m 755 ./../$(OUT) /usr/local/bin/$(OUT)

clean:
	rm -rf ./$(OUT_DIR) ./../$(OUT)

.PHONY: main compile format install clean
