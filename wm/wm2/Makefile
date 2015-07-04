# $NetBSD: Makefile,v 1.23 2015/07/04 16:18:41 joerg Exp $

DISTNAME=	wm2-4
PKGNAME=	wm2-4.0
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.all-day-breakfast.com/wm2/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.all-day-breakfast.com/wm2/
COMMENT=	Minimalist window manager for X

BUILD_TARGET=	depend wm2

USE_TOOLS+=	makedepend
USE_LANGUAGES=	c c++
MAKE_ENV+=	CCC=${CXX:Q}

INSTALLATION_DIRS=	bin share/doc/wm2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/wm2

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
