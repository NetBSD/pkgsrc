# $NetBSD: Makefile,v 1.9 2004/11/13 22:04:53 jlam Exp $

DISTNAME=	wm2-4
PKGNAME=	wm2-4.0
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.all-day-breakfast.com/wm2/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.all-day-breakfast.com/wm2/
COMMENT=	Minimalist window manager for X

ALL_TARGET=	depend wm2

USE_LANGUAGES=	c c++
USE_BUILDLINK3=	YES
USE_X11BASE=	YES
MAKE_ENV+=	CCC="${CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/man/cat1/wm2.0

.include "../../mk/bsd.pkg.mk"
