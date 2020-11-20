# $NetBSD: Makefile,v 1.56 2020/11/20 20:42:53 wiz Exp $

DISTNAME=		libX11-1.7.0
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Base X libraries from modular Xorg X11
LICENSE=		mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--disable-specs
PKGCONFIG_OVERRIDE+=	x11.pc.in

CONFIGURE_ENV+=		FILE_MAN_SUFFIX=5

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull
# for reallocarray()
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

.include "../../mk/pthread.buildlink3.mk"
CPPFLAGS.OSF1+=		${PTHREAD_CFLAGS} # Required by compiler if including pthread.h
CPPFLAGS.MirBSD+=	${PTHREAD_CFLAGS}
LDFLAGS.MirBSD+=	${PTHREAD_LDFLAGS}
LDFLAGS.OpenBSD+=	${PTHREAD_LDFLAGS}

BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.11.1

TOOL_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${PREFIX}/bin/tradcpp -Uunix"

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}

# XXX This needs to match the version of xcb-proto we get for the
# target by buildlink3.
TOOL_DEPENDS+=		xorgproto-[0-9]*:../../x11/xorgproto
.endif

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
