# $NetBSD: Makefile,v 1.10 2026/07/08 07:28:01 wiz Exp $

DISTNAME=	xlsfonts-1.0.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Lists available fonts

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
