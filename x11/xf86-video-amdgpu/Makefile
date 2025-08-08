# $NetBSD: Makefile,v 1.28 2025/08/08 11:28:14 wiz Exp $

DISTNAME=	xf86-video-amdgpu-25.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI (Tonga, Carrizo, Iceland, Fiji, Stoney) driver
LICENSE=	mit AND x11

USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	amdgpu

.include "../../devel/meson/build.mk"
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
