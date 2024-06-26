# Top-level Makefile

# List of subdirectories containing Makefiles
SUBDIRS := Inter-process-communication synchronization  # Add more directories as needed

# Default target: Build all subdirectories
all:
	@for dir in $(SUBDIRS); do \
		echo "Making in $$dir..."; \
		$(MAKE) -C $$dir; \
	done

# Clean target: Clean all subdirectories
clean:
	@for dir in $(SUBDIRS); do \
		echo "Cleaning in $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all clean
