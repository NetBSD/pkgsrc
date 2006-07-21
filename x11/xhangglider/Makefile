# $NetBSD: Makefile,v 1.10 2006/07/21 14:27:56 jlam Exp $
#

DISTNAME=	xhangglider-0.94.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.netfort.gr.jp/~take/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netfort.gr.jp/~take/linux/xhang-en.html
COMMENT=	Hanggliders fly in the background of the X screen

USE_IMAKE=		yes
PKGSRC_MAKE_ENV+=	PREFIX=${PREFIX}

post-extract:
	${RM} ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/xhangglider.man

do-install:
	cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} make install
	cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} make install.dat

.include "../../mk/bsd.pkg.mk"
