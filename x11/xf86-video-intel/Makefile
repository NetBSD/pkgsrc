# $NetBSD: Makefile,v 1.40 2018/03/07 11:57:43 wiz Exp $

DISTNAME=	xf86-video-intel-2.99.917
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

CONFLICTS+=	xf86-video-i810-[0-9]*

CONFIGURE_ARGS+=	--enable-dri

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
