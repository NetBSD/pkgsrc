# $NetBSD: Makefile,v 1.10 2011/11/01 06:02:40 sbd Exp $
#

DISTNAME=	xonclock-0.0.9.4
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xonclock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xonclock.sourceforge.net/
COMMENT=	Analog clock
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
