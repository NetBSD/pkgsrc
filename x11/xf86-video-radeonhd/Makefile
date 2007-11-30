# $NetBSD: Makefile,v 1.2 2007/11/30 12:00:42 joerg Exp $
#

DISTNAME=	xf86-video-radeonhd-1.0.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://ati.amd.com/
COMMENT=	Modular X.org driver for Radeon HD series

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=     gmake pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
