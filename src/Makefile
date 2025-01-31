CXX ?= clang++
CXXFLAGS := \
			-Wall \
			-Wextra \
			-std=c++17

LDFLAGS := \
		   -lSDL2 \
		   -lSDL2_image \
		   -Wno-unused-command-line-argument

CFMT := clang-format
OUT := quick-pic
OUT_DIR := build
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CXXFLAGS += -ggdb \
				-gdwarf-2 \
				-DDEBUG \
				-O0 \
				-fstandalone-debug \
				-fno-stack-protector
else
	CXXFLAGS += -DNDEBUG -Og
endif

SRCS := $(wildcard ./*.cpp)
HPPS := $(wildcard ./*.hpp ./*.h)
OBJS := $(SRCS:./%.cpp=$(OUT_DIR)/%.o)

$(OUT_DIR)/%.o: ./%.cpp 
	$(CXX) $(CXXFLAGS) $< -o $(CWD)$@ -c

MAKE_DIR := mkdir -p $(OUT_DIR)/

main:
	$(MAKE_DIR)
	$(MAKE) compile

debug:
	$(MAKE_DIR)
	$(MAKE) DEBUG=1 compile

compile: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o ./../$(OUT)

format:
	$(CFMT) -i $(SRCS) $(HPPS) $(HS)

install:
	install -m 755 ./../$(OUT) /usr/local/bin/$(OUT)

clean:
	rm -rf ./$(OUT_DIR) ./../$(OUT)

.PHONY: main debug compile format install clean
