# $NetBSD: Makefile,v 1.3 2001/11/15 07:58:50 jlam Exp $
#

DISTNAME=	wmCalClock-1.25
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	another WindowMaker calendar/clock dockapp

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES

WRKSRC=			${WRKDIR}/${DISTNAME}/Src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		EXTRALIBS="-lsocket -lnsl"
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${PREFIX}/bin/

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
