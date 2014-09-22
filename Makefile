OBJS =	Entity.o Item.o ActorState.o Actor.o Monster.o Player.o Tile.o TileMap.o GameScreen.o SplashScreen.o Level.o Game.o ConfigParser.o enDJIN.o

INCLUDES = -I c:/MinGW/include -I c:/Python27/include

LIBS = -lsfml-system -lsfml-window -lsfml-graphics  -lsfml-network  -lsfml-audio -lsfgui -ljsoncpp

TARGET =	enDJIN.exe

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 $(INCLUDES)

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
