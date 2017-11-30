# $NetBSD: Makefile,v 1.1 2017/11/30 15:53:19 wiz Exp $

DISTNAME=	xf86-video-vboxvideo-1.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg VirtualBox virtual video driver

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
#.include "../../x11/randrproto/buildlink3.mk"
#BUILDLINK_DEPMETHOD.libXext?=	build
#.include "../../x11/libXext/buildlink3.mk"
#.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
