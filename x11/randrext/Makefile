# $NetBSD: Makefile,v 1.7 2004/04/24 16:34:28 minskim Exp $

DISTNAME=		randrext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X RandR extension (Headers and documentation files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    randr.pc.in

.include "../../mk/bsd.prefs.mk"

# Xrandr won't build without the X Extension library which is only present
# in XFree86>=4.3. For this reason we don't need the header files.
.if !exists(${X11BASE}/include/X11/extensions/extutil.h)
PKG_SKIP_REASON=	"Xrandr won't build without the X Extension"
PKG_SKIP_REASON+=	"library which is only present in XFree86>=4.3."
PKG_SKIP_REASON+=	"For this reason we don't need the header files."
.endif

.include "../../mk/bsd.pkg.mk"
