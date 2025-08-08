# $NetBSD: grammar.mk,v 1.7 2025/08/08 21:06:16 wiz Exp $
#
# Common logic to build and install tree-sitter grammars.
#
# GRAMMAR_LIBRARY_NAME
#  Name of the grammar library to build and install.
#

GRAMMAR_LIBRARY_NAME?=	lib${PKGBASE}
GRAMMAR_SOURCE_DIR?=	src
GRAMMAR_C_STANDARD?=	c99

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes

do-build:
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	libtool --mode=compile ${CC} ${CPPFLAGS} ${CFLAGS} -std=${GRAMMAR_C_STANDARD} -I. -c -fPIC parser.c
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	if [ -f scanner.c ]; then libtool --mode=compile ${CC} ${CPPFLAGS} ${CFLAGS} -std=${GRAMMAR_C_STANDARD} -I. -c -fPIC scanner.c; fi
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	if [ -f scanner.cc ]; then libtool --mode=compile ${CXX} ${CPPFLAGS} ${CXXFLAGS} -I. -c -fPIC scanner.cc; fi
	cd ${WRKSRC}/${GRAMMAR_SOURCE_DIR} && \
	libtool --mode=link ${CXX} ${LDFLAGS} -module -rpath ${PREFIX}/lib -shared -avoid-version -o ${GRAMMAR_LIBRARY_NAME}.la *.lo

INSTALLATION_DIRS+=	lib

do-install:
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/${GRAMMAR_SOURCE_DIR}/${GRAMMAR_LIBRARY_NAME}.la ${DESTDIR}${PREFIX}/lib
