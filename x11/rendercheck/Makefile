# $NetBSD: Makefile,v 1.4 2012/10/29 05:06:48 asau Exp $
#

DISTNAME=	rendercheck-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	XRender test application

GNU_CONFIGURE=	yes
USE_FEATURES=	err
USE_TOOLS+=	pkg-config

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
