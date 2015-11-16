# the $< is the first item in the dependencies list
# $@ and $^ are the left and right sides of the :, respectively
# $* is the left side of the :, without suffix

ODIR = obj
dummy_build_folder := $(shell mkdir -p $(ODIR))

CC = g++
CFLAGS = -pipe -O2 -Wall -Wextra
HEADERS = parameters.h agent.h object.h basket.h myWorld.h ObjectInterface.h 
_OBJ = main.o agent.o myWorld.o object.o basket.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
IDIR = -I. -I ~/Softwares/enki-master    -I ~/Softwares/enki-master/viewer -I/usr/include/qt4 -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtCore
LDIR = -L. -L ~/Softwares/enki-master/enki -L ~/Softwares/enki-master/viewer \
	   -lenki -lenkiviewer -lgsl -lgslcblas -lm -lQtOpenGL -lQtGui -lQtCore -lGLU -lGL -lX11 -lXext
OUT = main
	
all: $(OUT) 
$(OUT): $(OBJ)
	$(CC) -o $@ $^ $(LDIR)
	
$(ODIR)/%.o: %.cpp $(HEADERS) 
	$(CC) -c -o $@ $< $(CFLAGS) $(IDIR)
	
clean:	
	rm -rf $(ODIR)/*.o *.txt *~ $(OUT)
