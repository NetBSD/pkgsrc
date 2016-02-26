# $NetBSD: Makefile,v 1.18 2016/02/26 11:27:15 jperkin Exp $

DISTNAME=		libXrandr-1.5.0
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X RandR Library from X.org

CONFLICTS+=		Xrandr-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xrandr.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.5
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
