# $NetBSD: Makefile,v 1.1 2015/08/22 13:31:39 wiz Exp $

DISTNAME=	xf86-video-xgi-1.6.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg XGI video driver

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
#.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
#.include "../../x11/renderproto/buildlink3.mk"
#.include "../../x11/videoproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
