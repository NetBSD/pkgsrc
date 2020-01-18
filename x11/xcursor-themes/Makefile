# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:59 rillig Exp $

DISTNAME=	xcursor-themes-1.0.6
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=data/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular X.org xcursor themes

BUILD_DEPENDS+=	xcursorgen>=1.0.5:../../x11/xcursorgen

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-cursordir=${PREFIX}/share/icons

.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
