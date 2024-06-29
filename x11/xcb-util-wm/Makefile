# $NetBSD: Makefile,v 1.11 2024/06/29 17:07:51 cheusov Exp $

DISTNAME=	xcb-util-wm-0.4.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	Client and window-manager helpers for ICCCM and EWMH
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config m4

PKGCONFIG_OVERRIDE+=	ewmh/xcb-ewmh.pc.in
PKGCONFIG_OVERRIDE+=	icccm/xcb-icccm.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
