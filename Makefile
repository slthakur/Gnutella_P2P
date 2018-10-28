CXX = g++
CXXFLAGS = -Wall -I. -g -O0

DEPS = err_reporting.cpp  crs/crs_socket.cpp
OBJ = err_reporting.o crs/crs_socket.o
%.o: %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

p2p_crs: $(OBJ)
	$(CXX) $(CXXFLAGS) crs/crs_main.cpp -o $@ $^

DEPS = err_reporting.cpp client/query_socket.cpp
OBJ = err_reporting.o client/query_socket.o
%.o: %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

p2p_client: $(OBJ)
	$(CXX) $(CXXFLAGS) client/client_main.cpp -o $@ $^

clean:
	rm -rf *.o
