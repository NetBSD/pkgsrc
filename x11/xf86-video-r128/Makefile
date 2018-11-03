# $NetBSD: Makefile,v 1.22 2018/11/03 10:51:54 wiz Exp $

DISTNAME=	xf86-video-r128-6.12.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Rage128 video driver

CONFLICTS=		xf86-video-ati<6.9.0

CONFIGURE_ARGS+=	--enable-dri

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
