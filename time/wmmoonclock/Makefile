# $NetBSD: Makefile,v 1.24 2016/02/26 10:37:09 jperkin Exp $

DISTNAME=	wmMoonClock-1.27
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	http://reality.sgiweb.org/freeware/source/wmMoonClock/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Shows lunar ephemeris to fairly high accuracy

WRKSRC=		${WRKDIR}/${DISTNAME}/Src
USE_TOOLS+=	gmake

OPSYSVARS+=		MAKE_FLAGS
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS.SunOS+=	EXTRA_LOCAL_LIBS=-lsocket

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
