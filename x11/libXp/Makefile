# $NetBSD: Makefile,v 1.10 2016/02/26 11:27:15 jperkin Exp $

DISTNAME=		libXp-1.0.3
CATEGORIES=		x11 print
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Print Service Extension Library

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xp.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "native"
XPRINT_CFLAGS=	-I${X11BASE}/include
XPRINT_LIBS=	-Wl,-rpath,${X11BASE}/lib -L${X11BASE}/lib -lX11 -lXext -lXau

CONFIGURE_ARGS+=	XPRINT_CFLAGS=${XPRINT_CFLAGS:Q} \
			XPRINT_LIBS=${XPRINT_LIBS:Q}
.endif

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/printproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
