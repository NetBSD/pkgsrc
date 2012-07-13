# $NetBSD: Makefile,v 1.1 2012/07/13 14:19:47 wiz Exp $
#

DISTNAME=	xcb-util-0.3.6
PKGNAME=	xcb-util036-0.3.6
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB Utilities (old 0.3.6 release)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/xcb-util036
USE_TOOLS+=	pkg-config gmake gm4
USE_LIBTOOL=	yes
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/xcb-util036/lib
#LIBS+=	${COMPILER_RPATH_FLAG}${PREFIX}/xcb-util036/lib
BUILDLINK_PASSTHRU_RPATHDIRS=	${PREFIX}/xcb-util036/lib

PKGCONFIG_OVERRIDE+=	atom/xcb-atom.pc.in
PKGCONFIG_OVERRIDE+=	aux/xcb-aux.pc.in
PKGCONFIG_OVERRIDE+=	event/xcb-event.pc.in
PKGCONFIG_OVERRIDE+=	icccm/xcb-icccm.pc.in
PKGCONFIG_OVERRIDE+=	image/xcb-image.pc.in
PKGCONFIG_OVERRIDE+=	keysyms/xcb-keysyms.pc.in
PKGCONFIG_OVERRIDE+=	property/xcb-property.pc.in
PKGCONFIG_OVERRIDE+=	renderutil/xcb-renderutil.pc.in
PKGCONFIG_OVERRIDE+=	reply/xcb-reply.pc.in

.include "../../devel/gperf/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
