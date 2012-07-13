# $NetBSD: Makefile,v 1.8 2012/07/13 14:21:58 wiz Exp $
#

DISTNAME=	xcb-util-0.3.9
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB Utilities

PKG_DESTDIR_SUPPORT=	user-destdir

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
