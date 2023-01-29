# $NetBSD: Makefile,v 1.29 2023/01/29 21:18:12 ryoon Exp $

DISTNAME=	hsetroot-1.0.5
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=himdel/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/himdel/hsetroot
COMMENT=	Allows you to compose wallpapers for X
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-as-needed

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hsetroot ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hsr-outputs ${DESTDIR}${PREFIX}/bin

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
