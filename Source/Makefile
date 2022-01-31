
  UOS=$(shell uname)
  ifeq ($(OS),Windows_NT)
        PLATFORM = Windows
    else
		ifeq ($(UOS),Linux)
			PLATFORM = Linux
		endif
	endif

  ifeq ($(PLATFORM),Windows)
    CC = C:/raylib/mingw/bin/g++.exe
    exename ?= MysticEngine2.exe
    CFLAGS  = -s  -O3 -static -Os -std=c99 -Wall -Iexternal -DPLATFORM_DESKTOP -lopengl32 -lraylib -lgdi32 -lwinmm -Wl,--subsystem,windows
  endif

  ifeq ($(PLATFORM),Linux)
    CC = g++
    exename ?= MysticEngine2
    CFLAGS  = -Wall -std=c99 -Wno-missing-braces -s -O3 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
  endif

  all: $(TARGET)
	  $(CC) MysticEngine2.cpp -o $(exename) $(CFLAGS)
