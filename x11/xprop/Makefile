# $NetBSD: Makefile,v 1.16 2022/11/09 13:14:31 joerg Exp $

DISTNAME=	xprop-1.2.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Property displayer for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
