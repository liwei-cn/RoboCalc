# the $< is the first item in the dependencies list
# $@ and $^ are the left and right sides of the :, respectively
# $* is the left side of the :, without suffix

ODIR = obj
dummy_build_folder := $(shell mkdir -p $(ODIR))

CC = g++
CFLAGS = -pipe -O2 -Wall -Wextra
HEADERS = parameters.h agent.h myWorld.h ObjectInterface.h 
_OBJ = main.o agent.o myWorld.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
IDIR = -I. -I/home/liwei/Softwares/enki-master -I/home/liwei/Softwares/enki-master/viewer \
		-I/usr/include/qt4 -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtOpenGL
LDIR = -L. -L/home/liwei/Softwares/enki-master/enki -L/home/liwei/Softwares/enki-master/viewer \
	   -lenki -lenkiviewer -lgsl -lgslcblas -lQtOpenGL -lQtGui -lQtCore -lGLU -lGL
OUT = main
	
all: $(OUT) 
$(OUT): $(OBJ)
	$(CC) -o $@ $^ $(LDIR)
	
$(ODIR)/%.o: %.cpp $(HEADERS) 
	$(CC) -c -o $@ $< $(CFLAGS) $(IDIR)
	
clean:	
	rm -rf $(ODIR)/*.o *.txt *~ $(OUT)
