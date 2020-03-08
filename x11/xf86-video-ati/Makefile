# $NetBSD: Makefile,v 1.52 2020/03/08 18:30:53 maya Exp $

DISTNAME=	xf86-video-ati-19.1.0
PKGREVISION=	1
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

CONFIGURE_ARGS+=	--enable-glamor

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.18.1
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.58
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
