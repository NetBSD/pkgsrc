# $NetBSD: Makefile,v 1.1.1.1 2007/02/28 03:21:51 reed Exp $
#

DISTNAME=	xconsole-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X11 client to display console messages

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
