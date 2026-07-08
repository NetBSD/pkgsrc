# $NetBSD: Makefile,v 1.8 2026/07/08 07:23:19 wiz Exp $

DISTNAME=		xkbutils-1.0.7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Small utilities utilizing the X11 XKeyboard (XKB) extension

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
