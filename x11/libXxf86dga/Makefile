# $NetBSD: Makefile,v 1.6 2008/05/24 21:45:16 tnn Exp $
#

DISTNAME=		libXxf86dga-1.0.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Library for the XFree86-DGA X extension

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

PKGCONFIG_OVERRIDE+=	xxf86dga.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

BUILDLINK_API_DEPENDS.xf86dgaproto+=	xf86dgaproto>=2.0.3

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
