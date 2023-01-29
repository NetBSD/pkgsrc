# $NetBSD: Makefile,v 1.54 2023/01/29 21:18:27 ryoon Exp $

PKGNAME=	xf86-video-intel-2.99.917.20210115
PKGREVISION=	1
COMMIT_ID=	31486f40f8e8f8923ca0799aea84b58799754564
DISTNAME=	xf86-video-intel-${COMMIT_ID}
CATEGORIES=	x11
#MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
MASTER_SITES=	https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/archive/${COMMIT_ID}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
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

RELRO_SUPPORTED=	partial

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		virtual
.if defined(OPSYS_HAS_TIMERFD)
CONFIGURE_ARGS+=	--enable-tools
PLIST.virtual=		yes
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tools
.endif

# Assumes platform compiler has SSE2, etc
ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

X11_DRV_NAME=	intel
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
