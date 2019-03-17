# only OPPA specific output files and rules
#

OBJDIRS += $(OBJ)/oppa

# add precompiler defines for OPPA
DEFS += -DOPPA_SUPPORT

CCFLAGS += -lwiringPi

# add objects for OPPA
OPPAOBJS = \
$(OBJ)/oppa/oppa.o \
$(OBJ)/oppa/oppa_display.o 


# OPPA functions
$(OBJ)/oppa/%.o: src/oppa/%.c
	@echo Compiling $<...
	$(CC) $(CDEFS) $(CCFLAGS) -lwiringPi -c $< -o $@
