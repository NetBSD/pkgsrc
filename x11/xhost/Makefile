# $NetBSD: Makefile,v 1.15 2022/11/09 13:14:29 joerg Exp $

DISTNAME=	xhost-1.0.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Server access control program for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
