# $NetBSD: Makefile,v 1.1.1.1 2011/11/08 10:49:35 ryoon Exp $

DISTNAME=	abclock-1.0d
CATEGORIES=	time
MASTER_SITES=	http://odur.let.rug.nl/~kleiweg/abclock/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://odur.let.rug.nl/~kleiweg/abclock/
COMMENT=	Analogue Bitmap Clock
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
