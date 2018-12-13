# $NetBSD: Makefile,v 1.28 2018/12/13 17:31:57 jperkin Exp $

DISTNAME=	wmmoonclock-1.29
PKGNAME=	${DISTNAME:C/moonclock/MoonClock/}
CATEGORIES=	x11 time
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dockapps.net/wmmoonclock
COMMENT=	Shows lunar ephemeris to fairly high accuracy
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
