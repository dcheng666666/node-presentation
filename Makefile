all: v8-shell v8-shell-extend libuv-async-read-file

v8-shell: v8-shell.cc
	 g++ -I /usr/local/Cellar/v8/9.5.172.25/libexec -I /usr/local/Cellar/v8/9.5.172.25/libexec/include -L /usr/local/Cellar/v8/9.5.172.25/libexec/ v8-shell.cc -o out/v8-shell -lv8 -lv8_libbase -lv8_libplatform -lv8 -licuuc -licui18n -stdlib=libc++ -std=c++14 -DV8_COMPRESS_POINTERS

v8-shell-extend: v8-shell-extend.cc
	 g++ -I /usr/local/Cellar/v8/9.5.172.25/libexec -I /usr/local/Cellar/v8/9.5.172.25/libexec/include -L /usr/local/Cellar/v8/9.5.172.25/libexec/ v8-shell-extend.cc -o out/v8-shell-extend -lv8 -lv8_libbase -lv8_libplatform -lv8 -licuuc -licui18n -stdlib=libc++ -std=c++14 -DV8_COMPRESS_POINTERS

libuv-async-read-file: libuv-async-read-file.c
	gcc -I /usr/local/Cellar/libuv/HEAD-e592ebe/include -L /usr/local/Cellar/libuv/HEAD-e592ebe/lib libuv-async-read-file.c -o out/libuv-async-read-file -luv

clean:
	rm -rf out/*