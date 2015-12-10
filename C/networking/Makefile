all: udp_server udp_client udp_broadcast_receiver udp_broadcast_sender network_interfaces_1 network_interfaces_2
	@mkdir -p ./bin
	@echo "done!"

clean:
	rm -rf ./bin/*

udp_server:
	gcc udp_server.c -o bin/udp_server

udp_server_test:
	nc -u 127.0.0.1 8888

udp_client:
	gcc udp_client.c -o bin/udp_client

udp_broadcast_receiver:
	gcc udp_broadcast_receiver.c -o bin/udp_broadcast_receiver

udp_broadcast_sender:
	gcc udp_broadcast_sender.c -o bin/udp_broadcast_sender

network_interfaces_1:
	gcc network_interfaces_1.c -o bin/network_interfaces_1

network_interfaces_2:
	gcc network_interfaces_2.c -o bin/network_interfaces_2