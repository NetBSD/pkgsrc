# $NetBSD: Makefile,v 1.30 2023/11/12 13:23:45 wiz Exp $
#

DISTNAME=	xonclock-0.0.9.4
PKGREVISION=	13
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xonclock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xonclock.sourceforge.net/
COMMENT=	Analog clock
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

LDFLAGS.DragonFly=	-lm -lXrender
LDFLAGS.SunOS+=		-lm -lXrender -lrt

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
