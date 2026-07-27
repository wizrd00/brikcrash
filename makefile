.SUFFIXES: .c .o .h
CC = clang
.if "${CC}" == "clang"
CFLAGS := -std=c99 -O3 -Werror -Wall -Wextra -Wpedantic
CFLAGS_SHARED := -shared
CFLAGS_PIC := -fPIC
CFLAGS_PIE := -fPIE
.elif "${CC}" == "gcc"
CFLAGS := -std=gnu99 -O3 -Werror -Wall -Wextra -Wpedantic
CFLAGS_SHARED := -shared
CFLAGS_PIC := -fPIC
CFLAGS_PIE := -fPIE
.else
.error unsupported compiler : ${CC}
.endif
SRC_DIR := source
INC_DIR := include
BIN_DIR := binary
LIB_DIR := library

SRC_FILES != find ${SRC_DIR} -name *.c
HDR_FILES != find ${INC_DIR} -name *.h
OBJ_FILES != find ${SRC_DIR} -name *.c | sed 's/${SRC_DIR}/${BIN_DIR}/g' | sed 's/\.c/\.o/g'

INCLUDE_FLAGS := -I${INC_DIR}

TERRENITY := ${LIB_DIR}/libterrenity.so
BRIKCRASH := brikcrash

POINTER_SYM := "\e[91m->\e[0m"

${BRIKCRASH} : ${BIN_DIR} ${OBJ_FILES} ${HDR_FILES} ${TERRENITY}
	@/bin/echo -e ${POINTER_SYM} "\e[96mlinking modules into" $@ "\e[0m"
	echo ${SRC_FILES}
	${CC} ${CFLAGS} ${CFLAGS_PIC} ${CFLAGS_PIE} ${OBJ_FILES} ${TERRENITY} -o $@
	@/bin/echo -e ${POINTER_SYM} "\e[93mstrip" $@ "\e[0m"
	@strip $@

${BIN_DIR} :
	@mkdir -p ${BIN_DIR}
	@mkdir -p ${BIN_DIR}/background
	@mkdir -p ${BIN_DIR}/ball
	@mkdir -p ${BIN_DIR}/brick
	@mkdir -p ${BIN_DIR}/paddle
	@mkdir -p ${BIN_DIR}/keyboard
	echo "hello"

.for src in ${SRC_FILES}
NEW_OBJ := ${src:S/${SRC_DIR}/${BIN_DIR}/:S/.c/.o/}
NEW_HDR := ${src:S/${SRC_DIR}/${INC_DIR}/:S/.c/.h/}
${NEW_OBJ} : ${src} ${NEW_HDR}
	@/bin/echo -e ${POINTER_SYM} "\e[93mcompiling module" ${src} "\e[0m"
	${CC} -c ${CFLAGS} ${CFLAGS_PIC} ${INCLUDE_FLAGS} ${src} -o $@
.endfor

clean :
	rm ${OBJ_FILES} ${BRIKCRASH}

clear : clean
