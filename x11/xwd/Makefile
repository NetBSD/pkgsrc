# $NetBSD: Makefile,v 1.3 2007/07/28 00:52:34 joerg Exp $
#

DISTNAME=	xwd-1.0.1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Dump X11 display or window to XWD X Window Dump image file

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"

# Should this be in libX11/buildlink3.mk?
# Package 'inputproto', required by 'X11', not found
.include "../../x11/inputproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
