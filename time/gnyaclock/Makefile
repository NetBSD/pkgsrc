# $NetBSD: Makefile,v 1.19 2012/10/08 13:04:18 asau Exp $
#

DISTNAME=	gnya
PKGNAME=	gnyaclock-20001218
PKGREVISION=	3
CATEGORIES=	time x11
MASTER_SITES=	http://www.is.titech.ac.jp/~sadayosi/lab/h-takasi/
EXTRACT_SUFX=	.shar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.is.titech.ac.jp/~sadayosi/lab/h-takasi/h.html
COMMENT=	Accessory with Bezier curve

WRKSRC=		${WRKDIR}/gnyaclock
USE_IMAKE=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnyaclock ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gnyaclock.man \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/gnyaclock.1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
