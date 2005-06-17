# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:38 jlam Exp $
#

DISTNAME=	wmCalClock-1.25
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
