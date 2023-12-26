.POSIX:
.DELETE_ON_ERROR:
.SUFFIXES:

VERBOSE  := false
AUTORUN  := true
SRCDIR   := src

BINDIR   := bin
TMPDIR   := bin/build
TARGET   := bin/glwrap

CC        = gcc
LD        = $(CC)
CPPFLAGS  = -I$(SRCDIR)
CFLAGS    = -std=c99 -pedantic -Wall -Wextra -Werror
LDFLAGS   =
LDLIBS    = -ldl -lGL
MDFLAGS   = -MM -MT $(@:.d=.o)
RM       := rm -rf
MKDIR    := mkdir -p
TESTD    := test -d

SOURCES  := $(shell find $(SRCDIR) -name "*.c")
OBJECTS  := $(SOURCES:%.c=$(TMPDIR)/%.o)
DEPENDS  := $(SOURCES:%.c=$(TMPDIR)/%.d)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS) $(DEPENDS)
	$(E) "[LD] $@"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(LD) -o $@ $(LDFLAGS) $(OBJECTS) $(LDLIBS)

$(TMPDIR)/%.o: %.c
	$(E) "[CC] $<"; $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(TMPDIR)/%.d: %.c
	$(Q) $(TESTD) $(@D) || $(MKDIR) $(@D)
	$(Q) $(CC) $(CPPFLAGS) $(MDFLAGS) $< -MF $@

.PHONY: clean
clean:
	$(E) "[RM] $(TARGET)"
	$(Q) $(RM) $(TARGET)
	$(E) "[RM] $(TMPDIR)"
	$(Q) $(RM) $(TMPDIR)

.PHONY: mrproper
mrproper: clean
	$(E) "[RM] $(BINDIR)"
	$(Q) $(RM) $(BINDIR)

.PHONY: run
run: $(TARGET)
	$(Q) ./$<

.PHONY: todo
todo:
	$(E) "[TODO] Unfinished tasks:"
	$(Q) grep -r --exclude-dir=".git" \
	          --exclude="Makefile" --exclude="*.swp" \
	          TODO | cut --complement -d':' -f2 | \
	          column -ts ":"

# The VERBOSE setting will supress
# all command output and replace it
# with pretty messages instead

ifneq ($(VERBOSE), false)
E = @true
else
E = @echo
Q = @
endif

# The AUTORUN setting will run the
# binary when the build is complete
# Used only for debugging purposes

ifneq ($(AUTORUN), false)
.DEFAULT_GOAL := run
endif

# Include header dependecies found
# with the preprocessor to ensure # changes trigger recompilation

include $(wildcard $(DEPENDS))
