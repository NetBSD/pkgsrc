# $NetBSD: Makefile,v 1.2 2012/10/08 13:04:16 asau Exp $

DISTNAME=	abclock-1.0d
CATEGORIES=	time
MASTER_SITES=	http://odur.let.rug.nl/~kleiweg/abclock/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://odur.let.rug.nl/~kleiweg/abclock/
COMMENT=	Analogue Bitmap Clock
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
