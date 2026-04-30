BIN = /usr/local/bin/tento

install:
	g++ -O2 -DDATADIR=\"/usr/share/source-highlight\" -o $(BIN) main.cpp $(shell pkg-config --cflags --libs source-highlight)

clean:
	rm -f $(BIN)
