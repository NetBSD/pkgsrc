# $NetBSD: Makefile,v 1.7 2004/04/24 16:54:34 minskim Exp $
#

DISTNAME=		libXrandr-1.0.2
PKGNAME=		Xrandr-1.0.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X RandR extension (Library)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xrandr.pc.in

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../mk/bsd.prefs.mk"

# Xrandr won't build without the X Extension library which is only present
# in XFree86>=4.3.
.if !exists(${X11BASE}/include/X11/extensions/extutil.h)
PKG_FAIL_REASON=	"${PKGNAME} won't build without the X Extension"
PKG_FAIL_REASON+=	"library which is only present in XFree86>=4.3."
.endif

.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
