# $NetBSD: Makefile,v 1.3 2001/01/12 12:27:01 dent Exp $
#

DISTNAME=	xhangglider-0.94.0
CATEGORIES=	x11
MASTER_SITES=	http://www.netfort.gr.jp/~take/linux/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.netfort.gr.jp/~take/linux/xhang-en.html

USE_IMAKE=	yes
BUILD_ENV+=	PREFIX=${PREFIX}

post-extract:
	${RM} ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/xhangglider.man

do-install:
	cd ${WRKSRC} ; make install
	cd ${WRKSRC} ; make install.dat

.include "../../mk/bsd.pkg.mk"
