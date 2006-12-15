# $NetBSD: Makefile,v 1.16 2006/12/15 20:33:01 joerg Exp $
#

DISTNAME=	wmCalClock-1.25
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	http://reality.sgiweb.org/freeware/source/wmCalClock/

MAINTAINER=	wiz@NetBSD.org
# HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Another WindowMaker calendar/clock dockapp

WRKSRC=		${WRKDIR}/${DISTNAME}/Src
USE_X11BASE=	YES
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRALIBS="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${PREFIX}/bin/

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
