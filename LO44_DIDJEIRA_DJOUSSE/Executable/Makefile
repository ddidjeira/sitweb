TARGET = main.o bc.o
c= gcc
CFLAGS= -c -Wall -fPIC
launcher=BC
all:$(launcher)
BC : $(TARGET)
	$(c) $(TARGET) -o BC
	clear
	@echo "Compilation terminé"
	@echo "./BC"
	./BC
main.o : main.c bc.h 
	$(c) $(CFLAGS) main.c -o main.o
bc.o : bc.c bc.h
	$(c) $(CFLAGS) bc.c -o bc.o
clean :
	rm -rf *.o
lib: $(TARGET)
	$(c) -shared -Wl,-soname,libtest.so $(TARGET) -o libbc.so
