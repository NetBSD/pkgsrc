# $NetBSD: Makefile,v 1.45 2021/10/17 11:22:57 nia Exp $

PKGNAME=	xf86-video-intel-2.99.917.20200515
COMMIT_ID=	5ca3ac1a90af177eb111a965e9b4dd8a27cc58fc
DISTNAME=	xf86-video-intel-${COMMIT_ID}
CATEGORIES=	x11
#MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
MASTER_SITES=	https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/archive/${COMMIT_ID}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver
LICENSE=	x11

CONFLICTS+=	xf86-video-i810-[0-9]*

CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--enable-dri3

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config automake autoconf autoreconf

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	virtual
.if (${OPSYS} == "Linux") || \
    (${OPSYS} == "NetBSD" && exists(/usr/include/sys/timerfd.h))
PLIST.virtual=	yes
.endif

# Assumes platform compiler has SSE2, etc
ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
