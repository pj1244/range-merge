CC= g++
VPATH =./

SOURCE=$(wildcard ./*.cpp )

SNOTDIR=$(notdir $(SOURCE))
OBJS=$(patsubst %.cpp, %.o, $(SNOTDIR) )
SOURCE_C = ${wildcard $(BS_TOMMATH_PATH)/*.c }
SNOTDIR_C=$(notdir $(SOURCE_C))
OBJS_C= $(patsubst %.c,%.o,$(SNOTDIR_C))

INCS_DIRS = -I. -I/usr/include -I/usr/local/include 

SYSLIB=-lpthread -lpcap -lIceUtil -lIce -lrt -lodbc -lboost_regex -lboost_system -lboost_date_time -lboost_filesystem -lboost_thread  -lACE \
 -Wl,-Bdynamic  -lrt -lglib-2.0
CFLAGS= -g -c -std=c++0x -Wunused -fpermissive -DDEBUG 

TARGET=./app
all: ${TARGET}
${TARGET}: ${OBJS} $(OBJS_C)
	${CC}  -o ${TARGET} ${OBJS} ${SYSLIB}  $(OBJS_C)
	
.cpp.o:
	${CC} ${CFLAGS} $(INCS_DIRS) $<

.c.o:
	gcc ${CFLAGS} $(INCS_DIRS) $<

clean:
	rm -f ${TARGET}
	rm -f *.o
print:
	@echo VPATH:
	@echo $(VPATH)
	@echo BS_SMARTICE:
	@echo $(BS_SMARTICE)
	@echo SOURCE_SMARTICE:
	@echo $(SOURCE_SMARTICE)
	@echo OBJS_SMARTICE:
	@echo $(OBJS_SMARTICE)
	@echo source:
	@echo $(SOURCE)
	@echo snotdir:
	@echo $(SNOTDIR)
	@echo source_c:
	@echo $(SOURCE_C)
	@echo objs:
	@echo $(OBJS)
	@echo objc:
	@echo $(OBJS_C)
