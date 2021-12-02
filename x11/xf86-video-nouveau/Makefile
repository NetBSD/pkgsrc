# $NetBSD: Makefile,v 1.15 2021/12/02 18:15:27 nia Exp $

DISTNAME=	xf86-video-nouveau-1.0.16
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	New (or nouveau) NVidia driver for modular X.org

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_BUILTIN_NAME=	xf86-video-nouveau
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
