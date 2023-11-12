# $NetBSD: Makefile,v 1.27 2023/11/12 13:24:34 wiz Exp $

DISTNAME=	xf86-video-amdgpu-23.0.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI (Tonga, Carrizo, Iceland, Fiji, Stoney) driver
LICENSE=	mit AND x11

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	amdgpu
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
