# $NetBSD: Makefile,v 1.4 2001/08/29 22:41:25 jlam Exp $

DISTNAME=	wm2-4
PKGNAME=	wm2-4.0
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.all-day-breakfast.com/wm2/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.all-day-breakfast.com/wm2/
COMMENT=	Minimalist window manager for X

ALL_TARGET=	depend wm2

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
MAKE_ENV+=	CCC="${CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/man/cat1/wm2.0

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
