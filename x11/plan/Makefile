# $NetBSD: Makefile,v 1.1 1998/09/04 08:09:53 frueauf Exp $
#

DISTNAME=	plan-1.7.2
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.fu-berlin.de/pub/unix/graphics/plan/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html

USE_MOTIF=	YES

WRKSRC=		${WRKDIR}/src
ALL_TARGET=	netbsd

pre-install:
	${MKDIR} ${X11BASE}/libexec/plan ${X11BASE}/share/plan \
		${X11BASE}/share/plan/holiday
	${INSTALL_DATA} ${WRKDIR}/holiday/holiday_* ${X11BASE}/share/plan/holiday
.for file in HISTORY README
	${INSTALL_DATA} ${WRKDIR}/${file} ${X11BASE}/share/plan
.endfor

.include "../../mk/bsd.pkg.mk"
