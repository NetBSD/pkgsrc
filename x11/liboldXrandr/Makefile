# $NetBSD: Makefile,v 1.1.2.2 2007/06/14 22:03:08 salo Exp $
#

DISTNAME=		libXrandr-1.0.2
PKGNAME=		Xrandr-1.0.2
PKGREVISION=		3
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X RandR extension (Library)

CONFLICTS+=		libXrandr-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xrandr.pc.in

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
