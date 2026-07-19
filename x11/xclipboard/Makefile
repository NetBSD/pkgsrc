# $NetBSD: Makefile,v 1.5 2026/07/19 20:09:41 wiz Exp $

DISTNAME=		xclipboard-1.1.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Manage the X server clipboard
LICENSE=		x11

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
