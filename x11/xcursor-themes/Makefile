# $NetBSD: Makefile,v 1.4 2023/02/23 17:10:47 wiz Exp $

DISTNAME=	xcursor-themes-1.0.7
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=data/}
EXTRACT_SUFX=	.tar.xz

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
