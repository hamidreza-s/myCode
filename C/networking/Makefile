all: udp_server udp_client
	@echo "done!"
udp_server:
	gcc udp_server.c -o udp_server

udp_server_test:
	nc -u 127.0.0.1 8888

udp_client:
	gcc udp_client.c -o udp_client
