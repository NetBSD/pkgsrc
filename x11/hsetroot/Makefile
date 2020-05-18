# $NetBSD: Makefile,v 1.27 2020/05/18 10:26:25 nia Exp $

DISTNAME=	hsetroot-1.0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=himdel/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/himdel/hsetroot
COMMENT=	Allows you to compose wallpapers for X
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hsetroot ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hsr-outputs ${DESTDIR}${PREFIX}/bin

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
