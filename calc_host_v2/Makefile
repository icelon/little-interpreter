
######################################################################
##                     
## my.project          
## Built with /usr/bin/mygcc-build-project-makefile-mini-v2.1       
##                     
######################################################################





all: folder    obj/app.o  obj/lib_calc_early_v0.o  obj/lib_hex.o  obj/lib_host.o  obj/lib_uart_mini.o 
	@echo "- linking to app"
	@gcc  obj/app.o  obj/lib_calc_early_v0.o  obj/lib_hex.o  obj/lib_host.o  obj/lib_uart_mini.o    -o obj/app

folder:
	@mkdir -p obj

run:	obj/app
	@obj/app

obj/app.o: app.c
	@echo -n "- compiling app ... "
	@gcc -I./ -I/idp.do/mysrc/lib app.c -c -o obj/app.o
	@echo "done" 

obj/lib_calc_early_v0.o: lib_calc_early_v0.c
	@echo -n "- compiling lib_calc_early_v0 ... "
	@gcc -I./ -I/idp.do/mysrc/lib lib_calc_early_v0.c -c -o obj/lib_calc_early_v0.o
	@echo "done" 

obj/lib_hex.o: lib_hex.c
	@echo -n "- compiling lib_hex ... "
	@gcc -I./ -I/idp.do/mysrc/lib lib_hex.c -c -o obj/lib_hex.o
	@echo "done" 

obj/lib_host.o: lib_host.c
	@echo -n "- compiling lib_host ... "
	@gcc -I./ -I/idp.do/mysrc/lib lib_host.c -c -o obj/lib_host.o
	@echo "done" 

obj/lib_uart_mini.o: lib_uart_mini.c
	@echo -n "- compiling lib_uart_mini ... "
	@gcc -I./ -I/idp.do/mysrc/lib lib_uart_mini.c -c -o obj/lib_uart_mini.o
	@echo "done" 

clean:
	@echo "- cleaning objs"
	@rm -f obj/*

