# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:38 jlam Exp $
#

DISTNAME=	gnya
PKGNAME=	gnyaclock-20001218
CATEGORIES=	time x11
MASTER_SITES=	http://www2.is.titech.ac.jp/~sadayosi/lab/h-takasi/
EXTRACT_SUFX=	.shar

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www2.is.titech.ac.jp/~sadayosi/lab/h-takasi/h.html
COMMENT=	Accessory with Bezier curve

WRKSRC=		${WRKDIR}/gnyaclock
USE_IMAKE=	YES

INSTALLATION_DIRS=	bin man/ja_JP.EUC/man1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gnyaclock ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/gnyaclock.man \
			${PREFIX}/man/ja_JP.EUC/man1/gnyaclock.1

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
