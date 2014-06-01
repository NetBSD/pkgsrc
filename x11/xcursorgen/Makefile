# $NetBSD: Makefile,v 1.26 2014/06/01 08:03:27 wiz Exp $

DISTNAME=	xcursorgen-1.0.6
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/xorg/app/xcursorgen/
COMMENT=	Prepare X11 cursor sets for use with libXcursor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
