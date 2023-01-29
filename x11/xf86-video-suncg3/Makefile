# $NetBSD: Makefile,v 1.16 2023/01/29 21:18:29 ryoon Exp $

DISTNAME=	xf86-video-suncg3-1.1.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	CG3 video driver for the Xorg X server
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

ONLY_FOR_PLATFORM+=	*-*-sparc *-*-sparc64

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	suncg3
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
