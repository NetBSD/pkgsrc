# $NetBSD: Makefile,v 1.16 2022/12/26 22:10:43 wiz Exp $

DISTNAME=	xcb-util-0.4.1
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.xz

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
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
