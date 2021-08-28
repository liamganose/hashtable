CC = g++
SRCDIR := src
BUILDDIR := build
INCDIR := include
INC := -I $(INCDIR)
SRCEXT := cpp
INCEXT := hpp
INCLUDES := $(wildcard $(addsuffix /*$(INCEXT), $(INCDIR)))
SOURCES += $(wildcard $(addsuffix /*$(SRCEXT), $(SRCDIR)))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
BINDIR := bin
TARGET := $(BINDIR)/main.exe

$(TARGET): $(OBJECTS)
	-@mkdir bin || :
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(INCLUDES) Makefile
	-@mkdir build || :
	$(CC) $(INC) -c -o $@ $<