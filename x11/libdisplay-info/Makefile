# $NetBSD: Makefile,v 1.2 2025/01/02 09:52:42 nia Exp $

DISTNAME=	libdisplay-info-0.2.0
CATEGORIES=	x11
MASTER_SITES=	https://gitlab.freedesktop.org/emersion/libdisplay-info/-/releases/${PKGVERSION_NOREV}/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://emersion.pages.freedesktop.org/libdisplay-info
COMMENT=	EDID and DisplayID library
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
