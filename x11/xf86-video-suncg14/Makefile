# $NetBSD: Makefile,v 1.12 2021/12/02 18:15:28 nia Exp $

DISTNAME=	xf86-video-suncg14-1.1.2
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	CG14 video driver for the Xorg X server
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

.include "options.mk"

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_BUILTIN_NAME=	xf86-video-suncg14
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
