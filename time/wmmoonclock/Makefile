# $NetBSD: Makefile,v 1.19 2010/02/12 00:28:36 joerg Exp $

DISTNAME=	wmMoonClock-1.27
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	http://reality.sgiweb.org/freeware/source/wmMoonClock/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Shows lunar ephemeris to fairly high accuracy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/Src
USE_TOOLS+=	gmake
USE_X11BASE=	YES

MAKE_FLAGS+=	EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
EXTRA_LOCAL_LIBS=	-lsocket
.endif

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
