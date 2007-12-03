# $NetBSD: Makefile,v 1.3 2007/12/03 19:33:14 xtraeme Exp $
#

DISTNAME=	xf86-video-radeonhd-1.0.0
PKGREVISION=	1
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
