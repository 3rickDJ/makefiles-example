OBJS := main.o
BINARY = main.exe
LIBS =-lGL -lglut -lGLU
FLAGS = -Wall
CXX = g++

all: app

%.o: %.cpp %.h
	$(CXX) $(FLAGS) -c $^

app: main.cpp
	$(CXX) $(FLAGS) -o $@ $^ $(LIBS)

# main: $(OBJS)
# 	$(CXX) -o $(BINARY) $(FLAGS) $? $(LIBS)

# %.o: %.cpp
# 	$(CXX) -c $? $(FLAGS) $(LIBS)

clean:
	@-rm -rf *.o main.exe
