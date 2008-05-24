# $NetBSD: Makefile,v 1.7 2008/05/24 21:45:19 tnn Exp $
#

DISTNAME=	xf86-video-radeonhd-1.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://ati.amd.com/
COMMENT=	Modular X.org driver for Radeon HD series

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=     gmake pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
