# $NetBSD: Makefile,v 1.5 2003/03/29 12:42:44 jmmv Exp $
#

DISTNAME=	wmCalClock-1.25
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	another WindowMaker calendar/clock dockapp

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRALIBS="-lsocket -lnsl"
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${PREFIX}/bin/

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
