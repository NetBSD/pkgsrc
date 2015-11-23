# $NetBSD: Makefile,v 1.1 2015/11/23 12:46:49 wiz Exp $

DISTNAME=	xf86-video-amdgpu-1.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI (Tonga, Carrizo, Iceland, Fiji, Stoney) driver

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
