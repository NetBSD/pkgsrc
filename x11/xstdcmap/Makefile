# $NetBSD: Makefile,v 1.8 2026/07/12 20:03:55 wiz Exp $

DISTNAME=	xstdcmap-1.0.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Selectively defines standard colormap properties
LICENSE=	x11

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
