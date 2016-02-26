# $NetBSD: Makefile,v 1.17 2016/02/26 11:27:21 jperkin Exp $

DISTNAME=	xf86-video-wsfb-0.4.0
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg wsdisplay framebuffer video driver

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
