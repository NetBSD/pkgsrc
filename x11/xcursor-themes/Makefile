# $NetBSD: Makefile,v 1.1 2019/02/15 09:42:19 wiz Exp $

DISTNAME=	xcursor-themes-1.0.6
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_XORG:=data/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org xcursor themes

BUILD_DEPENDS+=	xcursorgen>=1.0.5:../../x11/xcursorgen

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
