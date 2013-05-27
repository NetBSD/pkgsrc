# $NetBSD: Makefile,v 1.1 2013/05/27 10:48:59 rodent Exp $
#

DISTNAME=	oclock-1.0.3
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Simple analog clock to make a round window
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
