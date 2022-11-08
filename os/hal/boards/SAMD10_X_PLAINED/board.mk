# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/SAMD10_X_PLAINED/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/SAMD10_X_PLAINED

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
