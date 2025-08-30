# $NetBSD: Makefile,v 1.1 2025/08/30 13:37:10 pho Exp $
#
# Replacement Makefile for gkrellaclock for portability
#

OBJS=	gkrellaclock.lo

PKG_CONFIG_DEPS=	gtk+-2.0
EXTRA_CFLAGS!=		pkg-config ${PKG_CONFIG_DEPS} --cflags
EXTRA_LIBS!=		pkg-config ${PKG_CONFIG_DEPS} --libs

.PHONY: all
all: gkrellaclock.la

gkrellaclock.la: ${OBJS}
	${LIBTOOL} --tag=CC --mode=link \
		${CC} ${LDFLAGS} ${EXTRA_LIBS} ${.ALLSRC} -o ${.TARGET} \
		-module -shared -avoid-version -rpath ${PLUGIN_DIR:Q}

.SUFFIXES: .c .lo
.c.lo:
	${LIBTOOL} --tag=CC --mode=compile \
		${CC} -c ${CFLAGS} ${EXTRA_CFLAGS} ${.IMPSRC} -shared

.PHONY: install
install: gkrellaclock.la
	${INSTALL_LIB_DIR} ${DESTDIR}${PLUGIN_DIR}
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${.ALLSRC} ${DESTDIR}${PLUGIN_DIR}
