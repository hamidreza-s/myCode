CC=gcc

BIN_DIR=bin
OBJS=src/*.o

all: stack_array \
	stack_linked_list \
	circular_linked_list \
	doubly_linked_list \
	singly_linked_list
	mkdir -p $(BIN_DIR)
	mv $^ $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR) $(OBJS)

circular_linked_list: src/circular_linked_list.o
	$(CC) -o $@ $<

doubly_linked_list: src/doubly_linked_list.o
	$(CC) -o $@ $<

singly_linked_list: src/singly_linked_list.o
	$(CC) -o $@ $<

stack_array: src/stack_array.o
	$(CC) -o $@ $<

stack_linked_list: src/stack_linked_list.o
	$(CC) -o $@ $<
