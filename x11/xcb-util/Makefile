# $NetBSD: Makefile,v 1.2 2009/04/25 11:31:32 wiz Exp $
#

DISTNAME=	xcb-util-0.3.4
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB Utilities

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	atom/xcb-atom.pc.in
PKGCONFIG_OVERRIDE+=	aux/xcb-aux.pc.in
PKGCONFIG_OVERRIDE+=	event/xcb-event.pc.in
PKGCONFIG_OVERRIDE+=	icccm/xcb-icccm.pc.in
PKGCONFIG_OVERRIDE+=	image/xcb-image.pc.in
PKGCONFIG_OVERRIDE+=	keysyms/xcb-keysyms.pc.in
PKGCONFIG_OVERRIDE+=	property/xcb-property.pc.in
PKGCONFIG_OVERRIDE+=	renderutil/xcb-renderutil.pc.in
PKGCONFIG_OVERRIDE+=	reply/xcb-reply.pc.in
PKGCONFIG_OVERRIDE+=	wm/xcb-wm.pc.in

.include "../../devel/gperf/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
