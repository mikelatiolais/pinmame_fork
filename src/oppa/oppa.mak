# only OPPA specific output files and rules
#

OBJDIRS += $(OBJ)/oppa

# add objects for OPPA
OPPAOBJS = \


# OPPA functions
$(OBJ)/oppa/%.o: src/oppa/%.c
	@echo Compiling $<...
	$(CC) $(CDEFS) $(CCFLAGS) -c $< -o $@
