# $NetBSD: Makefile,v 1.8 2020/11/24 10:53:06 nia Exp $

DISTNAME=	wmCalClock-1.25
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	http://reality.sgiweb.org/freeware/source/wmCalClock/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dockapps.net/wmcalclock
COMMENT=	Another WindowMaker calendar/clock dockapp

PREV_PKGPATH=	time/wmcalclock

WRKSRC=		${WRKDIR}/${DISTNAME}/Src
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV.SunOS+=	EXTRALIBS="-lsocket -lnsl"

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
