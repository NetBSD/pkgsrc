# $NetBSD: Makefile,v 1.18 2009/06/06 22:37:28 wiz Exp $
#

DISTNAME=		libX11-1.2.1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Base X libraries from modular Xorg X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-man-pages=3
CONFIGURE_ARGS+=	--without-xcb
PKGCONFIG_OVERRIDE+=	x11.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_ENV+=	CC_FOR_BUILD=${NATIVE_CC:Q} CPPFLAGS_FOR_BUILD=-I${PREFIX}/include
.endif

CPPFLAGS.OSF1+=		-pthread # Required by compiler if including pthread.h

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mhp)
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="cc -E -Uunix -"
.endif

.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/xcmiscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86bigfontproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
