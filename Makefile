

# Specify the directory where source files are located
SRCDIR = src


SRC_FILES = $(wildcard *.c) $(wildcard $(SRCDIR)/*.c)


OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))

# Use the 'patsubst' function to convert source paths to object paths
# and place object files in a build directory to keep the workspace clean
BUILDDIR = build
OBJS_PATH = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(filter $(SRCDIR)/%.c,$(SRC_FILES))) $(patsubst %.c,$(BUILDDIR)/%.o,$(filter main.c,$(SRC_FILES)))

SDL_CFLAGS=$(shell sdl2-config --cflags)
SDL_LDFLAGS=$(shell sdl2-config --libs)

SDL2_TTF_CFLAGS=$(shell pkg-config --cflags SDL2_ttf)
SDL2_TTF_LDFLAGS=$(shell pkg-config --libs SDL2_ttf)
SDL2_IMG_CFLAGS=$(shell pkg-config --cflags SDL2_image)
SDL2_IMG_LDFLAGS=$(shell pkg-config --libs SDL2_image)

TARGET=main

.PHONY : all clean

all:$(TARGET)

$(TARGET):$(OBJS_PATH)
	$(CC) $^ -o $@ $(SDL_LDFLAGS) $(SDL2_TTF_LDFLAGS) $(SDL2_IMG_LDFLAGS)

# compile .c to .o from root dir
$(BUILDDIR)/%.o : %.c
	mkdir -p $(BUILDDIR)
	$(CC) -c $^ -o ./$@ $(SDL2_TTF_CFLAGS) $(SDL2_IMG_CFLAGS) $(SDL_CFLAGS)

# compile .c to .o from src dir
$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(BUILDDIR)
	$(CC) -c $^ -o $@ $(SDL2_TTF_CFLAGS) $(SDL2_IMG_CFLAGS) $(SDL_CFLAGS)

clean:
	rm -r ./build

