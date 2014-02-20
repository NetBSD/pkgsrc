# $NetBSD: Makefile,v 1.6 2014/02/20 07:38:52 wiz Exp $

DISTNAME=	xcb-util-wm-0.4.1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	Client and window-manager helpers for ICCCM and EWMH
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	m4 pkg-config gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	ewmh/xcb-ewmh.pc.in
PKGCONFIG_OVERRIDE=	icccm/xcb-icccm.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
