# $NetBSD: Makefile,v 1.27 2017/09/06 09:03:06 wiz Exp $

DISTNAME=	xcursorgen-1.0.6
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/xorg/app/xcursorgen/
COMMENT=	Prepare X11 cursor sets for use with libXcursor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
