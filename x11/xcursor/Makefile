# $NetBSD: Makefile,v 1.24 2012/10/29 05:07:00 asau Exp $
#

DISTNAME=		libXcursor-1.1.2
PKGNAME=		${DISTNAME:S/libX/x/}
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Client-side cursor loading library for X

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		libXcursor-[0-9]*

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcursor.pc.in

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
