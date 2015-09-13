CC=gcc

LIBRARY_NAME=nanomsg
LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/

CFLAGS+= -Wall 
LDFLAGS+= -L$(LIBRARY_PATH) -l$(LIBRARY_NAME)

BIN_DIR=bin
OBJS=src/*.o

.PHONY: pipeline_test reqrep_test

all: pipeline reqrep
	mkdir -p $(BIN_DIR)
	mv $^ $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR) $(OBJS)

pipeline: src/pipeline.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

pipeline_test:
	@./$(BIN_DIR)/pipeline node0 "ipc:///tmp/pipeline.ipc" \
		& echo $$! > "/tmp/pipeline.pid"
	@sleep 1
	@./$(BIN_DIR)/pipeline node1 "ipc:///tmp/pipeline.ipc" "Hello" &
	@sleep 1
	@./$(BIN_DIR)/pipeline node1 "ipc:///tmp/pipeline.ipc" "Goodbye" &
	@sleep 1
	@kill `cat /tmp/pipeline.pid`


reqrep: src/reqrep.o
	$(CC) $(FLAGS) $(LDFLAGS) -o $@ $<


reqrep_test:
	@./$(BIN_DIR)/reqrep node0 "ipc:///tmp/reqrep.ipc" \
		& echo $$! > "/tmp/reqrep.pid"
	@sleep 1
	@./$(BIN_DIR)/reqrep node1 "ipc:///tmp/reqrep.ipc" &
	@kill `cat /tmp/reqrep.pid`