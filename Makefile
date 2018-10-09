GCCFLAGS=-Wall

all: PWM.o Backlight.o
  g++ -o PWM ../libs/PWM.o Backlight.o 

PWM.o: ../libs/PWM.cpp
	g++ ${GCCFLAGS} -o ../libs/PWM.o -c ../libs/PWM.cpp

Backlight.o: Backlight.cpp
	g++ ${GCCFLAGS} -o Backlight.o -c Backlight.cpp

clean:
	rm *.o
  rm ../libs/*.o
