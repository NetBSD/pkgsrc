# $NetBSD: Makefile,v 1.1 2014/02/16 23:05:33 wiz Exp $

PKGVERSION=		2.6.2
DISTNAME=		tinyxml_${PKGVERSION:S/./_/g}
PKGNAME=		tinyxml-${PKGVERSION}
CATEGORIES=		textproc devel lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tinyxml/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc@NetBSD.org
HOMEPAGE=		http://www.grinninglizard.com/tinyxml/
COMMENT=		Simple, small, C++ XML parser
LICENSE=		zlib

USE_LANGUAGES+=		c++
WRKSRC=			${WRKDIR}/${PKGBASE}
MAKE_ENV+=		SHLIB_MAJOR=2 SHLIB_MINOR=6 SHLIB_TEENY=2
MAKE_ENV+=              ${BSD_MAKE_ENV}

INSTALL_TARGET=		install includes
INSTALLATION_DIRS+=	include lib

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
