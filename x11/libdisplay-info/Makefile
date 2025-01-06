# $NetBSD: Makefile,v 1.3 2025/01/06 18:15:53 gutteridge Exp $

DISTNAME=	libdisplay-info-0.2.0
CATEGORIES=	x11
MASTER_SITES=	https://gitlab.freedesktop.org/emersion/libdisplay-info/-/releases/${PKGVERSION_NOREV}/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://emersion.pages.freedesktop.org/libdisplay-info
COMMENT=	EDID and DisplayID library
LICENSE=	mit

USE_TOOLS+=	pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/libdisplay-info.map

.include "../../devel/meson/build.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
