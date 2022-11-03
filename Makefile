CC = g++
FLAGS = -Wall -Werror

# Target: Dependencies
# 		Command to build Target Based On Dependencies

heap-demo: heapMain.o
	$(CC) $(FLAGS) $^ -o $@

heapMain.o: heapMain.cc heap.h
	$(CC) $(FLAGS) -c $<

clean:
	@-rm -f heap-demo
	@-rm -f *.o
