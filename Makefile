#defining project settings
project_name := "Nimble2D Egnine"
version := '"v0.0.1"'

#defining compiler settings
INCLUDE_PATHS := $(foreach wrd,$(wildcard src/),-I $(dir $(wrd))) \
	$(foreach wrd,$(wildcard include/),-I $(dir $(wrd)))
#INCLUDE_PATHS := $(foreach wrd,$(wildcard src/*/),-I $(dir $(wrd))) \
	#$(foreach wrd,$(wildcard include/*/),-I $(dir $(wrd)))
LIBS := -lraylib -lopengl32 -lgdi32 -lwinmm -llua54
CC := g++
CPP := c++20
DEBUGFLAGS_O := -std=$(CPP) -Wno-missing-braces -w -g -Wall -m64 -DDEBUG -DVERSION=$(version) $(INCLUDE_PATHS)
RELEASEFLAGS_O := -std=$(CPP) -Wno-missing-braces -w -O3 -Wall -m64 -DNDEBUG -DVERSION=$(version) $(INCLUDE_PATHS)

#defining paths
DIRS := ./obj ./obj/release ./obj/debug ./bin ./bin/release ./bin/debug
OUTPATH_DEBUG := bin/debug/$(project_name)
OUTPATH_RELEASE := bin/release/$(project_name)
OBJDIR_R := obj/release/
OBJDIR_D := obj/debug/

# getting header files
headers := $(wildcard src/*.h) $(wildcard src/*/*.h) $(wildcard include/*.h) $(wildcard include/*/*.h)
# getting source files
sources := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard include/*.cpp) $(wildcard include/*/*.cpp)
# getting object files
objects_r := $(patsubst %.cpp,$(OBJDIR_R)%.o,$(notdir $(sources)))
objects_d := $(patsubst %.cpp,$(OBJDIR_D)%.o,$(notdir $(sources)))

#setting vpath
VPATH := $(sort $(dir $(sources)))

default: rundebug

-include $(wildcard $(OBJDIR_D)*.d) $(wildcard $(OBJDIR_R)*.d)


.PHONY: clean rundebug runrelease default

rundebug: debug
	cd bin/debug/ && .\${project_name}.exe

runrelease: release
	cd bin/release/ && .\${project_name}.exe

release: | $(DIRS) $(objects_r) $(headers)
	@echo Compiling Executable
	@$(CC) obj/release/*.o -o $(OUTPATH_RELEASE) -mwindows -s -L lib/ $(LIBS)
	@echo Copying resources
	-@xcopy /y /s /q /d "./res" "bin/release"

debug: | $(DIRS) $(objects_d) $(headers)
	@echo Compiling Executable
	@$(CC) obj/debug/*.o -o $(OUTPATH_DEBUG) -L lib/ $(LIBS)
	@echo Copying resources
	-@xcopy /y /s /q /d "./res" "bin/debug"

$(DIRS):
	@echo "Folder $@ does not exist"
	@mkdir "$@"

$(OBJDIR_R)%.o: %.cpp
	@echo Compiling $< to $@
	@$(CC) -MMD -MP -c $< -o $@ $(RELEASEFLAGS_O)

$(OBJDIR_D)%.o:%.cpp
	@echo Compiling $< to $@
	@$(CC) -MMD -MP -c $< -o $@ $(DEBUGFLAGS_O)

clean:
	-@rmdir /s /q obj
	-@rmdir /s /q bin

