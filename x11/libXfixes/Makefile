# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 21:31:40 joerg Exp $
#

DISTNAME=		libXfixes-4.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org

CONFLICTS+=		Xfixes-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

# needs version 4 which defines xXFixesHideCursorReq
BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
