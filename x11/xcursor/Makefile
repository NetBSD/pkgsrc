# $NetBSD: Makefile,v 1.18 2006/03/04 21:31:12 jlam Exp $
#

DISTNAME=		libXcursor-1.1.2
PKGNAME=		${DISTNAME:S/libX/x/}
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Client-side cursor loading library for X

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xcursor.pc.in

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
