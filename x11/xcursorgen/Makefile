# $NetBSD: Makefile,v 1.30 2025/05/19 06:37:41 wiz Exp $

DISTNAME=	xcursorgen-1.0.9
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/xorg/app/xcursorgen/
COMMENT=	Prepare X11 cursor sets for use with libXcursor

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
