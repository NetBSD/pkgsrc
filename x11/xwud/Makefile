# $NetBSD: Makefile,v 1.13 2026/07/12 20:06:28 wiz Exp $

DISTNAME=	xwud-1.0.8
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Display XWD X Window Dump image file

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
