# $NetBSD: Makefile,v 1.8 2017/08/16 20:21:18 wiz Exp $

DISTNAME=	xcb-util-wm-0.4.1
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	Client and window-manager helpers for ICCCM and EWMH
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gm4 gmake pkg-config

PKGCONFIG_OVERRIDE=	ewmh/xcb-ewmh.pc.in
PKGCONFIG_OVERRIDE=	icccm/xcb-icccm.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
