# $NetBSD: Makefile,v 1.19 2006/04/06 06:22:56 reed Exp $
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

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xrandr.pc.in

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
BUILDLINK_API_DEPENDS.randrext+=	randrext>=1.0

.include "../../x11/Xrender/buildlink3.mk"
.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
