# $NetBSD: Makefile,v 1.7 2003/07/21 17:28:45 martti Exp $
#

DISTNAME=	wmCalClock-1.25
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11 time
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	Another WindowMaker calendar/clock dockapp

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
