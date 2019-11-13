cc=g++
flag=-g

.PHONY:all
all:client server

client:client.cc
	$(cc) -o $@ $^ $(flag)
server:server.cc
	$(cc) -o $@ $^ $(flag)

.PHONY:clean
clean:
	rm -f client server
