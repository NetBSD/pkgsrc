# $NetBSD: Makefile,v 1.1.1.1 1999/08/05 03:51:18 hubertf Exp $
#

DISTNAME=	xhangglider-0.92e
CATEGORIES=	x11
MASTER_SITES=	http://plaza.harmonix.ne.jp/~redstar/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://plaza.harmonix.ne.jp/~redstar/xhang-en.html

USE_IMAKE=	yes
BUILD_ENV+=	PREFIX=${PREFIX}

post-extract:
	${RM} ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/xhangglider.man

do-install:
	cd ${WRKSRC} ; make install
	cd ${WRKSRC} ; make install.dat

.include "../../mk/bsd.pkg.mk"
