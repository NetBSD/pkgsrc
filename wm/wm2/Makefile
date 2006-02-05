# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:15 joerg Exp $

DISTNAME=	wm2-4
PKGNAME=	wm2-4.0
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.all-day-breakfast.com/wm2/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.all-day-breakfast.com/wm2/
COMMENT=	Minimalist window manager for X

BUILD_TARGET=	depend wm2

USE_LANGUAGES=	c c++
USE_X11BASE=	YES
MAKE_ENV+=	CCC=${CXX:Q}

INSTALLATION_DIRS=	bin man/cat1

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/man/cat1/wm2.0

.include "../../mk/bsd.pkg.mk"
