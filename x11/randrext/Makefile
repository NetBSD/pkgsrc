# $NetBSD: Makefile,v 1.5 2004/04/24 11:56:00 grant Exp $

DISTNAME=		randrext-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		X RandR extension (Headers and documentation files)

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
