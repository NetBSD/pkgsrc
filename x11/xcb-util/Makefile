# $NetBSD: Makefile,v 1.14 2021/12/03 12:36:32 nia Exp $

DISTNAME=	xcb-util-0.4.0
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	XCB Utilities

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake gm4
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	xcb-util.pc.in
PKGCONFIG_OVERRIDE+=	xcb-atom.pc.in
PKGCONFIG_OVERRIDE+=	xcb-event.pc.in
PKGCONFIG_OVERRIDE+=	xcb-aux.pc.in

.include "../../devel/gperf/buildlink3.mk"
X11_BUILTIN_NAME=	xcb-util
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
