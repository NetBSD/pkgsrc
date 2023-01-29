# $NetBSD: Makefile,v 1.29 2023/01/29 21:18:28 ryoon Exp $

DISTNAME=	xf86-video-r128-6.12.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Rage128 video driver

CONFLICTS=		xf86-video-ati<6.9.0

CONFIGURE_ARGS+=	--enable-dri

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	r128
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
