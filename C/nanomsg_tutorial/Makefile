CC=gcc

LIBRARY_NAME=nanomsg
LIBRARY_PATH=/usr/local/lib

CFLAGS+= -Wall 
LDFLAGS+= -L$(LIBRARY_PATH) -l$(LIBRARY_NAME)

BIN_DIR=bin
OBJS=src/*.o

.PHONY: pipeline_test reqrep_test bus_test

all: pipeline reqrep bus
	mkdir -p $(BIN_DIR)
	mv $^ $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR) $(OBJS)

pipeline: src/pipeline.o
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

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
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)


reqrep_test:
	@./$(BIN_DIR)/reqrep node0 "ipc:///tmp/reqrep.ipc" \
		& echo $$! > "/tmp/reqrep.pid"
	@sleep 1
	@./$(BIN_DIR)/reqrep node1 "ipc:///tmp/reqrep.ipc" &
	@kill `cat /tmp/reqrep.pid`

bus: src/bus.o
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

bus_test:
	@./$(BIN_DIR)/bus node0 \
		ipc:///tmp/node0.ipc \
		ipc:///tmp/node1.ipc \
		ipc:///tmp/node2.ipc \
		& echo $$! > "/tmp/bus0.pid"
	@./$(BIN_DIR)/bus node1 \
		ipc:///tmp/node1.ipc \
		ipc:///tmp/node2.ipc \
		ipc:///tmp/node3.ipc \
		& echo $$! > "/tmp/bus1.pid"
	@./$(BIN_DIR)/bus node2 \
		ipc:///tmp/node2.ipc \
		ipc:///tmp/node3.ipc \
		& echo $$! > "/tmp/bus2.pid"
	@./$(BIN_DIR)/bus node3 \
		ipc:///tmp/node3.ipc \
		ipc:///tmp/node0.ipc \
		& echo $$! > "/tmp/bus3.pid"
	@sleep 10
	@kill `cat /tmp/bus0.pid`
	@kill `cat /tmp/bus1.pid`
	@kill `cat /tmp/bus2.pid`
	@kill `cat /tmp/bus3.pid`
