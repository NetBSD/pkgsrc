# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:15 tnn Exp $
#

DISTNAME=		libXp-1.0.0
CATEGORIES=		x11 print
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Print Service Extension Library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xp.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/printproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
