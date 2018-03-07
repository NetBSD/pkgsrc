# $NetBSD: Makefile,v 1.11 2018/03/07 11:57:43 wiz Exp $

DISTNAME=	xf86-video-nouveau-1.0.15
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	New (or nouveau) NVidia driver for modular X.org

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
