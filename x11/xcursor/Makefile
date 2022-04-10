# $NetBSD: Makefile,v 1.30 2022/04/10 08:53:18 nia Exp $
#

DISTNAME=		libXcursor-1.1.2
PKGNAME=		${DISTNAME:S/libX/x/}
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		https://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.freedesktop.org/Software/xlibs
COMMENT=		Client-side cursor loading library for X

CONFLICTS+=		libXcursor-[0-9]*

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcursor.pc.in

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8

X11_LIB=	libXcursor
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
