# $NetBSD: Makefile,v 1.3 2014/07/08 14:57:06 jperkin Exp $

DISTNAME=		tinyxml_2_6_2
PKGNAME=		tinyxml-2.6.2
PKGREVISION=		2
CATEGORIES=		textproc devel lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tinyxml/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc@NetBSD.org
HOMEPAGE=		http://www.grinninglizard.com/tinyxml/
COMMENT=		Simple, small, C++ XML parser
LICENSE=		zlib

USE_LANGUAGES+=		c++
USE_LIBTOOL=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}

INSTALLATION_DIRS+=	include lib

CXXFLAGS+=		-DTIXML_USE_STL=1

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.cc} tinystr.cpp
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.cc} tinyxml.cpp
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.cc} tinyxmlerror.cpp
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.cc} tinyxmlparser.cpp
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${COMPILE.cc} xmltest.cpp
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${LINK.cc} \
		-o libtinyxml.la *.lo -version-info 2:6:2 -rpath ${PREFIX}/lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libtinyxml.la \
		${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/tinyxml.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
