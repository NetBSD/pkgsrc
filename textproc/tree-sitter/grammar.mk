# $NetBSD: grammar.mk,v 1.4 2023/01/18 16:32:26 wiz Exp $
#
# Common logic to build and install tree-sitter grammars.
#
# GRAMMAR_LIBRARY_NAME
#  Name of the grammar library to build and install.
#

GRAMMAR_LIBRARY_NAME?=	lib${PKGBASE}
GRAMMAR_SOURCE_DIR?=	src

USE_LANGUAGES+=		c c++

do-build:
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	${CC} ${CFLAGS} -std=c99 -I. -c -fPIC parser.c
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	if [ -f scanner.c ]; then ${CC} ${CFLAGS} -std=c99 -I. -c -fPIC scanner.c; fi
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	if [ -f scanner.cc ]; then ${CXX} ${CXXFLAGS} -I. -c -fPIC scanner.cc; fi
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	${CXX} -shared -o ${GRAMMAR_LIBRARY_NAME}.so *.o

INSTALLATION_DIRS+=	lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/${GRAMMAR_SOURCE_DIR}/${GRAMMAR_LIBRARY_NAME}.so ${DESTDIR}${PREFIX}/lib
