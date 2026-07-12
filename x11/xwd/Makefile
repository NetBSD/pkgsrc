# $NetBSD: Makefile,v 1.15 2026/07/12 20:05:41 wiz Exp $

DISTNAME=	xwd-1.0.10
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Dump X11 display or window to XWD X Window Dump image file

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
