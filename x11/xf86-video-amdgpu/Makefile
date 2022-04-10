# $NetBSD: Makefile,v 1.22 2022/04/10 08:53:19 nia Exp $

DISTNAME=	xf86-video-amdgpu-19.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI (Tonga, Carrizo, Iceland, Fiji, Stoney) driver
LICENSE=	mit AND x11

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	amdgpu
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
