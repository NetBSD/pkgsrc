# $NetBSD: Makefile,v 1.6 2018/03/10 22:08:22 wiz Exp $

DISTNAME=	xlsfonts-1.0.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Lists available fonts

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
