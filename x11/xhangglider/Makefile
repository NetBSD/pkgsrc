# $NetBSD: Makefile,v 1.5 2002/03/09 17:05:46 hubertf Exp $
#

DISTNAME=	xhangglider-0.94.0
CATEGORIES=	x11
MASTER_SITES=	http://www.netfort.gr.jp/~take/linux/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.netfort.gr.jp/~take/linux/xhang-en.html
COMMENT=	Hanggliders fly in the background of the X screen

USE_IMAKE=	yes
BUILD_ENV+=	PREFIX=${PREFIX}

post-extract:
	${RM} ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/xhangglider.man

do-install:
	cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} make install
	cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} make install.dat

.include "../../mk/bsd.pkg.mk"
