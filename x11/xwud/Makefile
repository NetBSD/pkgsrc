# $NetBSD: Makefile,v 1.1.1.1 2007/02/11 01:22:51 reed Exp $
#

DISTNAME=	xwud-1.0.1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Display XWD X Window Dump image file

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"

# Should this be in libX11/buildlink3.mk?
# Package 'inputproto', required by 'X11', not found
.include "../../x11/inputproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
