# $NetBSD: Makefile,v 1.1 1999/09/24 04:37:32 jlam Exp $
#
# Makefile using LIBTOOL to generate a shared library from the static one.

SHELL=		/bin/sh

BINDIR=		${PREFIX}/bin
INCLUDEDIR=	${PREFIX}/include/X11
LIBDIR=		${PREFIX}/lib
MANDIR=		${PREFIX}/man

PROGS=		DESIGN/fdesign fd2ps/fd2ps
INCLUDES=	FORMS/forms.h

MAN1=		DESIGN/fdesign.1 fd2ps/fd2ps.1
MAN5=		FORMS/xforms.5

all:		libforms.la

libforms.la:	FORMS/libforms.a
	mkdir -p objects
	cd objects; \
	${AR} x ../FORMS/libforms.a; \
	for file in *.o; do \
		ln -f $${file} $${file%.o}.lo; \
	done
	${LIBTOOL} --mode=link ${CC} -o ${.TARGET} objects/*.lo \
		-rpath ${LIBDIR} -version-info ${SHLIB_MAJOR}:${SHLIB_MINOR}

install:	install-progs install-includes install-libs install-man

install-progs:	${PROGS}
	@for file in ${PROGS}; do \
		echo "${BSD_INSTALL_PROGRAM} $$file ${BINDIR}"; \
		${BSD_INSTALL_PROGRAM} $$file ${BINDIR}; \
	done

install-includes:	${INCLUDES}
	@for file in ${INCLUDES}; do \
		echo "${BSD_INSTALL_MAN} $$file ${INCLUDEDIR}"; \
		${BSD_INSTALL_MAN} $$file ${INCLUDEDIR}; \
	done

install-libs:	libforms.la
	${LIBTOOL} --mode=install ${BSD_INSTALL_DATA} libforms.la ${LIBDIR}
	@if [ -f ${LIBDIR}/libforms.a ]; then \
		echo "ln -sf libforms.a ${LIBDIR}/libxforms.a"; \
		ln -sf libforms.a ${LIBDIR}/libxforms.a; \
	fi
	@if [ -f ${LIBDIR}/libforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ]; then \
		echo "ln -sf libforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			${LIBDIR}/libxforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR}"; \
		ln -sf libforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			${LIBDIR}/libxforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR}; \
	fi

install-man:	${MAN1} ${MAN5}
	@for file in ${MAN1}; do \
		echo "${BSD_INSTALL_MAN} $$file ${MANDIR}/man1"; \
		${BSD_INSTALL_MAN} $$file ${MANDIR}/man1; \
	done
	@for file in ${MAN5}; do \
		echo "${BSD_INSTALL_MAN} $$file ${MANDIR}/man5"; \
		${BSD_INSTALL_MAN} $$file ${MANDIR}/man5; \
	done
	ln -sf xforms.5 ${MANDIR}/man5/forms.5
