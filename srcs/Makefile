TARGET=../bin/matrix_mul
INC=-I../include -I/usr/local/include
LIB=-L/usr/local/lib -L/usr/lib
bin=../bin
OBJDIR=../obj
SRCS=$(wildcard *.cpp)
#OBJFILE=$(patsubst %.cpp,%.o,$(SRCS))
#OBJS=$(subst srcs,obj,$(OBJFILE))
OBJS=$(addprefix $(OBJDIR)/, $(patsubst %.cpp,%.o,$(SRCS)))

CC=g++
OPT=-O3 $(INC) $(LIB)

CFLAGS=`pkg-config --cflags opencv`
LDFLAGS=`pkg-config --libs opencv`

$(info $(OBJS))

.PHONY: all clean
all: obj bin $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OPT) -o $@  $^ $(LDFLAGS) 

$(OBJDIR)/%.o:%.cpp
	$(CC) $(OPT) -o $@  -c $< $(LDFLAGS)

obj:
	mkdir -p ../obj

bin:
	mkdir -p ../bin

clean:
	rm -rf $(OBJDIR) $(TARGET) $(OBJS) $(bin)
