# Makefile for C Numerical Analysis Library

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
INCLUDES = -Iinclude
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
EXAMPLEDIR = examples

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Library name
LIBNAME = libnumerical_analysis.a
LIBRARY = $(LIBDIR)/$(LIBNAME)

# Example files
EXAMPLES = $(wildcard $(EXAMPLEDIR)/*.c)
EXAMPLE_BINS = $(EXAMPLES:$(EXAMPLEDIR)/%.c=%)

.PHONY: all clean library examples install

all: library examples

# Create directories
$(OBJDIR):
	@if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"

$(LIBDIR):
	@if not exist "$(LIBDIR)" mkdir "$(LIBDIR)"

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create static library
library: $(LIBRARY)

$(LIBRARY): $(OBJECTS) | $(LIBDIR)
	ar rcs $@ $^
	@echo "Library created: $(LIBRARY)"

# Compile examples
examples: $(EXAMPLE_BINS)

%: $(EXAMPLEDIR)/%.c $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $< -L$(LIBDIR) -lnumerical_analysis -lm -o $@

# Special targets for existing files that should use the library
bisectionMethod: bisectionMethod.c $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $< -L$(LIBDIR) -lnumerical_analysis -lm -o $@

NewtonRhapson: NewtonRhapson.c $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $< -L$(LIBDIR) -lnumerical_analysis -lm -o $@

SekantMethod: SekantMethod.c $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $< -L$(LIBDIR) -lnumerical_analysis -lm -o $@

RegulaFalsiMethod: RegulaFalsiMethod.c $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $< -L$(LIBDIR) -lnumerical_analysis -lm -o $@

GaussSiedel: GaussSiedel.c $(LIBRARY)
	$(CC) $(CFLAGS) $(INCLUDES) $< -L$(LIBDIR) -lnumerical_analysis -lm -o $@

# Clean build files
clean:
	@if exist "$(OBJDIR)" rmdir /s /q "$(OBJDIR)"
	@if exist "$(LIBDIR)" rmdir /s /q "$(LIBDIR)"
	@for %%f in ($(EXAMPLE_BINS)) do @if exist "%%f.exe" del "%%f.exe"
	@for %%f in (bisectionMethod NewtonRhapson SekantMethod RegulaFalsiMethod GaussSiedel) do @if exist "%%f.exe" del "%%f.exe"
	@if exist "*.exe" del "*.exe"

# Install library (copy to system directories - requires admin privileges)
install: library
	@echo "To install the library on Windows, run as Administrator:"
	@echo "copy $(LIBRARY) C:\Windows\System32\"
	@echo "copy include\*.h C:\Program Files\Microsoft Visual Studio\VC\include\"
	@echo ""
	@echo "Or for MinGW/MSYS2:"
	@echo "copy $(LIBRARY) C:\msys64\mingw64\lib\"
	@echo "copy include\*.h C:\msys64\mingw64\include\"

# Show help
help:
	@echo "Available targets:"
	@echo "  all          - Build library and examples"
	@echo "  library      - Build static library only"
	@echo "  examples     - Build example programs"
	@echo "  clean        - Remove build files"
	@echo "  install      - Show installation instructions"
	@echo "  help         - Show this help message"
	@echo ""
	@echo "Individual example targets:"
	@echo "  library_demo - Demo of all library functions"
	@echo "  bisectionMethod - Bisection method example"
	@echo "  NewtonRhapson - Newton-Raphson method example"
	@echo "  SekantMethod - Secant method example"
	@echo "  RegulaFalsiMethod - Regula Falsi method example"
	@echo "  GaussSiedel - Gauss-Seidel method example"
