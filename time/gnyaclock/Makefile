# $NetBSD: Makefile,v 1.1.1.1 2000/12/18 12:35:48 kei Exp $
#

DISTNAME=	gnya
PKGNAME=	gnyaclock-20001218
WRKSRC=		${WRKDIR}/gnyaclock
CATEGORIES=	time x11
MASTER_SITES=	http://www2.is.titech.ac.jp/~sadayosi/lab/h-takasi/
EXTRACT_SUFX=	.shar

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www2.is.titech.ac.jp/~sadayosi/lab/h-takasi/h.html

EXTRACT_CMD=    ${CAT} ${DOWNLOADED_DISTFILE} | ${SH}

USE_IMAKE=	YES
USE_XPM=	YES

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gnyaclock ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/gnyaclock.man \
			${PREFIX}/man/ja_JP.EUC/man1/gnyaclock.1

.include "../../mk/bsd.pkg.mk"
