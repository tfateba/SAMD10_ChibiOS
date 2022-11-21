# Required platform files.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS)/os/hal/ports/SAMD10/SAMD10D14AM/samd10_isr.c \
               $(CHIBIOS)/os/hal/ports/SAMD10/SAMD10D14AM/hal_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS)/os/hal/ports/SAMD10/SAMD10D14AM

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(HALCONFDIR),)
  ifeq ($(CONFDIR),)
    HALCONFDIR = .
  else
    HALCONFDIR := $(CONFDIR)
  endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))

else
endif

# Drivers compatible with the platform.
#include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/DMAv1/driver.mk
include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/GPIOv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/SPIv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/TIMERv1/driver.mk
include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/SYSTICKv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/UARTv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/RTCv1/driver.mk
include $(CHIBIOS)/os/hal/ports/SAMD10/LLD/WDGv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)
