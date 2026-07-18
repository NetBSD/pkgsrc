# $NetBSD: Makefile,v 1.21 2026/07/18 22:52:48 wiz Exp $

DISTNAME=	xclock-1.2.1
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Analog / digital clock for X

PREV_PKGPATH=	x11/xclock

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/meson/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
