# $NetBSD: Makefile,v 1.8 2022/04/04 09:47:04 wiz Exp $

DISTNAME=	xlsfonts-1.0.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Lists available fonts

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
