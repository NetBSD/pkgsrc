# $NetBSD: Makefile,v 1.33 2023/11/12 13:24:09 wiz Exp $

DISTNAME=	hsetroot-1.0.5
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=himdel/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/himdel/hsetroot
COMMENT=	Allows you to compose wallpapers for X
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-as-needed
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-as-needed

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hsetroot ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hsr-outputs ${DESTDIR}${PREFIX}/bin

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
