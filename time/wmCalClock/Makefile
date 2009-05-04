# $NetBSD: Makefile,v 1.3 2009/05/04 16:43:44 wiz Exp $
#

DISTNAME=	wmCalClock-1.25
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	http://reality.sgiweb.org/freeware/source/wmCalClock/

MAINTAINER=	wiz@NetBSD.org
# HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Another WindowMaker calendar/clock dockapp

PREV_PKGPATH=	time/wmcalclock

WRKSRC=		${WRKDIR}/${DISTNAME}/Src
USE_TOOLS+=	gmake

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRALIBS="-lsocket -lnsl"
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
