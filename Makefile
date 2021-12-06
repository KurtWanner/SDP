CC = g++
LD = $(CC)
GITBINARY = git
FIRMWAREREPO = simulator_libraries

CPPFLAGS = -MMD -MP -Os -DOBJC_OLD_DISPATCH_PROTOTYPES -g

WARNINGS = -Wall

LIB_DIR = simulator_libraries
CUS_DIR = custom_libraries

INC_DIRS = -I$(LIB_DIR) -I. -I$(CUS_DIR)

# Add new Class to this list
OBJS = $(LIB_DIR)/FEHLCD.o $(LIB_DIR)/FEHRandom.o $(LIB_DIR)/FEHSD.o $(LIB_DIR)/FEHUtility.o \
		$(LIB_DIR)/tigr.o $(CUS_DIR)/OBJECT.o $(CUS_DIR)/DINO.o $(CUS_DIR)/OBSTACLE.o \
		$(CUS_DIR)/Button.o $(CUS_DIR)/Graphics.o $(CUS_DIR)/Util.o

ifeq ($(OS),Windows_NT)
	LDFLAGS = -lopengl32 -lgdi32
	EXEC = game.exe
	SHELL := CMD
else
	LDFLAGS = -framework OpenGL -framework Cocoa
	EXEC = game.out
endif

SRC_FILES := $(wildcard ./*.cpp)
OBJ_FILES := $(patsubst ./%.cpp,./%.o,$(SRC_FILES))

$(EXEC): $(OBJ_FILES) $(OBJS)
	$(CC) $(CPPFLAGS) $(WARNINGS) $(INC_DIRS) $(OBJ_FILES) $(OBJS) -o $(EXEC) $(LDFLAGS)

./%.o: ./%.cpp
	$(CC) $(CPPFLAGS) $(WARNINGS) $(INC_DIRS) -c -o $@ $<

clean:
ifeq ($(OS),Windows_NT)
	del $(LIB_DIR)\*.o
	del $(LIB_DIR)\*.d
	del *.o *.d $(EXEC)
else
	rm $(LIB_DIR)/*.o $(LIB_DIR)/*.d
	rm *.o *.d $(EXEC)
endif