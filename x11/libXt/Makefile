# $NetBSD: Makefile,v 1.7 2008/01/29 03:37:02 bjs Exp $
#

DISTNAME=		libXt-1.0.5
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Toolkit Intrinsics library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-appdefaultdir=${PREFIX}/lib/X11/app-defaults
CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xt.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_ENV+=	CC_FOR_BUILD=${NATIVE_CC:Q} CPPFLAGS_FOR_BUILD=-I${PREFIX}/include
.endif

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
