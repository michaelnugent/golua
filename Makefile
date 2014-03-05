go: lib
	go build lua.go
	LD_LIBRARY_PATH=. ./lua

lib:
	gcc -c -fPIC lua-host.c
	gcc -shared -Wl,-soname,libluahost.so -o libluahost.so lua-host.o
	ln -s libluahost.so libluahost.so.1
	ln -s libluahost.so libluahost.so.1.0

test: lib
	gcc library_test.c -o library_test -L. -lluahost -llua
	LD_LIBRARY_PATH=. ./library_test "`cat hello_world.lua `"

clean:
	rm -f *.o
	rm -f libluahost.*
	rm -f library_test
	rm -f lua

