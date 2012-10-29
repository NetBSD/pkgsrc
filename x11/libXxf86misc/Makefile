# $NetBSD: Makefile,v 1.7 2012/10/29 05:06:36 asau Exp $
#

DISTNAME=		libXxf86misc-1.0.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Library for the XFree86-Misc X extension

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xxf86misc.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
