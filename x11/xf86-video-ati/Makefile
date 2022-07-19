# $NetBSD: Makefile,v 1.56 2022/07/19 11:59:05 hauke Exp $

DISTNAME=	xf86-video-ati-19.1.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Radeon video driver
LICENSE=	mit AND x11

CONFIGURE_ARGS+=	--enable-dri

CONFLICTS+=	xf86-video-ati6-[0-9]*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ARGS+=	--enable-glamor

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	ati
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.58
.include "../../x11/libdrm/buildlink3.mk"
BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.18.1
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
