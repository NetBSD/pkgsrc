# $NetBSD: grammar.mk,v 1.1 2023/01/18 08:18:16 wiz Exp $
#
# Common logic to build and install tree-sitter grammars.
#
# GRAMMAR_LIBRARY_NAME
#  Name of the grammar library to build and install.
#

GRAMMAR_LIBRARY_NAME?=	lib${PKGNAME}

USE_LANGUAGES+=		c c++

do-build:
	cd ${WRKSRC}/src && \
	${CC} ${CFLAGS} -std=c99 -I. -c -fPIC parser.c
	cd ${WRKSRC}/src && \
	if [ -f scanner.c ]; then ${CC} ${CFLAGS} -std=c99 -I. -c -fPIC scanner.c; else \
	${CXX} ${CXXFLAGS} -I. -c -fPIC scanner.cc; fi
	cd ${WRKSRC}/src && \
	${CXX} -shared -o ${GRAMMAR_LIBRARY_NAME}.so scanner.o parser.o

INSTALLATION_DIRS+=	lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/${GRAMMAR_LIBRARY_NAME}.so ${DESTDIR}${PREFIX}/lib
