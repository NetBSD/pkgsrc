# $NetBSD: Makefile,v 1.25 2023/01/29 21:18:28 ryoon Exp $

DISTNAME=	xf86-video-openchrome-0.6.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Openchrome/
COMMENT=	Modular Xorg OpenChrome driver for VIA UniChrome video chipsets

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ARGS+=	--enable-maintainer-mode
CONFIGURE_ARGS+=	--enable-dri

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		XvMC
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.XvMC=		yes
.endif

X11_DRV_NAME=	openchrome
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
