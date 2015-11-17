CC=gcc

LIBRARY_NAME=nanomsg
LIBRARY_PATH=/usr/local/lib
INCLUDE_PATH=/usr/local/include

CFLAGS+= -Wall 
LDFLAGS+= -I$(INCLUDE_PATH) -L$(LIBRARY_PATH) -l$(LIBRARY_NAME)

BIN_DIR=bin
OBJS=src/*.o

.PHONY: pipeline_test reqrep_test bus_test pair_test

all: prebuild pipeline reqrep bus pair
	@echo done!

prebuild:
	mkdir -p bin

clean:
	rm -rf $(BIN_DIR) $(OBJS)

pipeline:
	$(CC) src/pipeline.c -o  bin/pipeline $(CFLAGS) $(LDFLAGS)

pipeline_test:
	@./$(BIN_DIR)/pipeline node0 "ipc:///tmp/pipeline.ipc" \
		& echo $$! > "/tmp/pipeline.pid"
	@sleep 1
	@./$(BIN_DIR)/pipeline node1 "ipc:///tmp/pipeline.ipc" "Hello" &
	@sleep 1
	@./$(BIN_DIR)/pipeline node1 "ipc:///tmp/pipeline.ipc" "Goodbye" &
	@sleep 1
	@kill `cat /tmp/pipeline.pid`


reqrep:
	$(CC) src/reqrep.c -o bin/reqrep $(CFLAGS) $(LDFLAGS)


reqrep_test:
	@./$(BIN_DIR)/reqrep node0 "ipc:///tmp/reqrep.ipc" \
		& echo $$! > "/tmp/reqrep.pid"
	@sleep 1
	@./$(BIN_DIR)/reqrep node1 "ipc:///tmp/reqrep.ipc" &
	@kill `cat /tmp/reqrep.pid`

bus:
	$(CC) src/bus.c -o bin/bus $(CFLAGS) $(LDFLAGS)

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

pair:
	$(CC) src/pair.c -o bin/pair $(CFLAGS) $(LDFLAGS)


reqrep_test:
