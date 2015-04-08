
######################################################################
##                     
## my.project          
## Built with /usr/bin/mygcc-build-project-makefile-v4       
##                     
######################################################################





all:  app.interface  lib_calc_early_v0.interface  lib_hex.interface  lib_host.interface  lib_uart_mini.interface   app.private  lib_calc_early_v0.private  lib_hex.private  lib_host.private  lib_uart_mini.private   obj/komakino-i686/app.o  obj/komakino-i686/lib_calc_early_v0.o  obj/komakino-i686/lib_hex.o  obj/komakino-i686/lib_host.o  obj/komakino-i686/lib_uart_mini.o 
	@mkdir -p obj/komakino-i686
	@echo "- linking to app"
	@gcc  obj/komakino-i686/app.o  obj/komakino-i686/lib_calc_early_v0.o  obj/komakino-i686/lib_hex.o  obj/komakino-i686/lib_host.o  obj/komakino-i686/lib_uart_mini.o    -o obj/komakino-i686/app

run:	obj/komakino-i686/app
	@obj/komakino-i686/app

interfaces: 
	@echo "- touching interface private"
	@touch app.private
	@touch lib_calc_early_v0.private
	@touch lib_hex.private
	@touch lib_host.private
	@touch lib_uart_mini.private
	@echo "- touching interface public"
	@touch app.interface
	@touch lib_calc_early_v0.interface
	@touch lib_hex.interface
	@touch lib_host.interface
	@touch lib_uart_mini.interface

	@echo "- generating interface private for app"
	@cproto -S -I/idp.do/mysrc/lib  -I./   app.c > app.private
	@echo "- generating interface private for lib_calc_early_v0"
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_calc_early_v0.c > lib_calc_early_v0.private
	@echo "- generating interface private for lib_hex"
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_hex.c > lib_hex.private
	@echo "- generating interface private for lib_host"
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_host.c > lib_host.private
	@echo "- generating interface private for lib_uart_mini"
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_uart_mini.c > lib_uart_mini.private

	@echo "- generating interface public for app"
	@cproto -I/idp.do/mysrc/lib  -I./   app.c > app.interface
	@echo "- generating interface public for lib_calc_early_v0"
	@cproto -I/idp.do/mysrc/lib  -I./   lib_calc_early_v0.c > lib_calc_early_v0.interface
	@echo "- generating interface public for lib_hex"
	@cproto -I/idp.do/mysrc/lib  -I./   lib_hex.c > lib_hex.interface
	@echo "- generating interface public for lib_host"
	@cproto -I/idp.do/mysrc/lib  -I./   lib_host.c > lib_host.interface
	@echo "- generating interface public for lib_uart_mini"
	@cproto -I/idp.do/mysrc/lib  -I./   lib_uart_mini.c > lib_uart_mini.interface

obj/komakino-i686/app.o: app.interface app.private app.c
	@echo -n "- compiling app ... "
	@gcc -I/idp.do/mysrc/lib  -I./   app.c -c -o obj/komakino-i686/app.o
	@echo "done" 

app.interface: app.c
	@echo -n "- generating interface public for app ... "
	@cproto -I/idp.do/mysrc/lib  -I./   app.c > app.interface
	@echo "done" 

app.private: app.c
	@echo -n "- generating interface private for app ... "
	@cproto -S -I/idp.do/mysrc/lib  -I./   app.c > app.private
	@echo "done" 

obj/komakino-i686/lib_calc_early_v0.o: lib_calc_early_v0.interface lib_calc_early_v0.private lib_calc_early_v0.c
	@echo -n "- compiling lib_calc_early_v0 ... "
	@gcc -I/idp.do/mysrc/lib  -I./   lib_calc_early_v0.c -c -o obj/komakino-i686/lib_calc_early_v0.o
	@echo "done" 

lib_calc_early_v0.interface: lib_calc_early_v0.c
	@echo -n "- generating interface public for lib_calc_early_v0 ... "
	@cproto -I/idp.do/mysrc/lib  -I./   lib_calc_early_v0.c > lib_calc_early_v0.interface
	@echo "done" 

lib_calc_early_v0.private: lib_calc_early_v0.c
	@echo -n "- generating interface private for lib_calc_early_v0 ... "
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_calc_early_v0.c > lib_calc_early_v0.private
	@echo "done" 

obj/komakino-i686/lib_hex.o: lib_hex.interface lib_hex.private lib_hex.c
	@echo -n "- compiling lib_hex ... "
	@gcc -I/idp.do/mysrc/lib  -I./   lib_hex.c -c -o obj/komakino-i686/lib_hex.o
	@echo "done" 

lib_hex.interface: lib_hex.c
	@echo -n "- generating interface public for lib_hex ... "
	@cproto -I/idp.do/mysrc/lib  -I./   lib_hex.c > lib_hex.interface
	@echo "done" 

lib_hex.private: lib_hex.c
	@echo -n "- generating interface private for lib_hex ... "
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_hex.c > lib_hex.private
	@echo "done" 

obj/komakino-i686/lib_host.o: lib_host.interface lib_host.private lib_host.c
	@echo -n "- compiling lib_host ... "
	@gcc -I/idp.do/mysrc/lib  -I./   lib_host.c -c -o obj/komakino-i686/lib_host.o
	@echo "done" 

lib_host.interface: lib_host.c
	@echo -n "- generating interface public for lib_host ... "
	@cproto -I/idp.do/mysrc/lib  -I./   lib_host.c > lib_host.interface
	@echo "done" 

lib_host.private: lib_host.c
	@echo -n "- generating interface private for lib_host ... "
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_host.c > lib_host.private
	@echo "done" 

obj/komakino-i686/lib_uart_mini.o: lib_uart_mini.interface lib_uart_mini.private lib_uart_mini.c
	@echo -n "- compiling lib_uart_mini ... "
	@gcc -I/idp.do/mysrc/lib  -I./   lib_uart_mini.c -c -o obj/komakino-i686/lib_uart_mini.o
	@echo "done" 

lib_uart_mini.interface: lib_uart_mini.c
	@echo -n "- generating interface public for lib_uart_mini ... "
	@cproto -I/idp.do/mysrc/lib  -I./   lib_uart_mini.c > lib_uart_mini.interface
	@echo "done" 

lib_uart_mini.private: lib_uart_mini.c
	@echo -n "- generating interface private for lib_uart_mini ... "
	@cproto -S -I/idp.do/mysrc/lib  -I./   lib_uart_mini.c > lib_uart_mini.private
	@echo "done" 

clean:
	@echo "- use clean_all, clean_interfaces, clean_obj"

clean_all: clean_interfaces
	@echo "- cleaning all"
	@rm -f *.gch
	@rm -f *.o
	@rm -f app

clean_obj:
	@echo "- cleaning objs"
	@rm -f obj/komakino-i686/*

clean_interfaces:
	@echo "- cleaning interfaces"
	@rm -f *.interface
	@rm -f *.private

commit:  obj/komakino-i686/app.o  obj/komakino-i686/lib_calc_early_v0.o  obj/komakino-i686/lib_hex.o  obj/komakino-i686/lib_host.o  obj/komakino-i686/lib_uart_mini.o 
	@echo -n "- committing ..."
	@echo -n "."
	@cp obj/komakino-i686/./lib_calc_early_v0.o   /idp.do/mysrc/lib/
	@cp ./lib_calc_early_v0.h         /idp.do/mysrc/lib/
	@cp ./lib_calc_early_v0.interface /idp.do/mysrc/lib/
	@echo -n "."
	@cp obj/komakino-i686/./lib_hex.o   /idp.do/mysrc/lib/
	@cp ./lib_hex.h         /idp.do/mysrc/lib/
	@cp ./lib_hex.interface /idp.do/mysrc/lib/
	@echo -n "."
	@cp obj/komakino-i686/./lib_host.o   /idp.do/mysrc/lib/
	@cp ./lib_host.h         /idp.do/mysrc/lib/
	@cp ./lib_host.interface /idp.do/mysrc/lib/
	@echo -n "."
	@cp obj/komakino-i686/./lib_uart_mini.o   /idp.do/mysrc/lib/
	@cp ./lib_uart_mini.h         /idp.do/mysrc/lib/
	@cp ./lib_uart_mini.interface /idp.do/mysrc/lib/
	@echo " done"

library:  obj/komakino-i686/app.o  obj/komakino-i686/lib_calc_early_v0.o  obj/komakino-i686/lib_hex.o  obj/komakino-i686/lib_host.o  obj/komakino-i686/lib_uart_mini.o 
	@echo -n "library archive committing to lib_my.a ..." 
	@echo "#ifndef _lib_my_" > obj/komakino-i686/lib_my.h
	@echo "#define _lib_my_" >> obj/komakino-i686/lib_my.h
	@echo " " >> obj/komakino-i686/lib_my.h
	@echo "#include \"lib_calc_early_v0.h\" " >> obj/komakino-i686/lib_my.h
	@echo "#include \"lib_hex.h\" " >> obj/komakino-i686/lib_my.h
	@echo "#include \"lib_host.h\" " >> obj/komakino-i686/lib_my.h
	@echo "#include \"lib_uart_mini.h\" " >> obj/komakino-i686/lib_my.h
	@echo " " >> obj/komakino-i686/lib_my.h
	@echo "#endif " >> obj/komakino-i686/lib_my.h
	@ar -rs obj/komakino-i686/lib_my.a  obj/komakino-i686/lib_calc_early_v0.o  obj/komakino-i686/lib_hex.o  obj/komakino-i686/lib_host.o  obj/komakino-i686/lib_uart_mini.o  > /dev/null 2>/dev/null
	@echo " done"

