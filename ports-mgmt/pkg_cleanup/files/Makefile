.if exists(/usr/lib/libncursesw.so)
LDLIBS += -lncursesw
.else
LDLIBS += -lncurses
.endif
LDLIBS += -L${LOCALBASE}/lib -lcdialog
CFLAGS += -I${LOCALBASE}/include

all: pkg_cleanup

pkg_cleanup: pkg_cleanup.c
