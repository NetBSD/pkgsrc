# $NetBSD: Makefile,v 1.6 2003/11/10 16:13:28 gavan Exp $

DISTNAME=	wm2-4
PKGNAME=	wm2-4.0
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.all-day-breakfast.com/wm2/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.all-day-breakfast.com/wm2/
COMMENT=	Minimalist window manager for X

ALL_TARGET=	depend wm2

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_GCC_SHLIB=	YES
MAKE_ENV+=	CCC="${BUILDLINK_CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wm2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/man/cat1/wm2.0

.include "../../mk/bsd.pkg.mk"
