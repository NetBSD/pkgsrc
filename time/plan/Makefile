# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:22 wiz Exp $
#

DISTNAME=	plan-1.8.4
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/plan/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html

USE_MOTIF=	YES

ALL_TARGET=	netbsd

pre-install:
	${MKDIR} ${X11PREFIX}/libexec/plan ${X11PREFIX}/share/plan \
		${X11PREFIX}/share/plan/holiday
	${RM} -f ${WRKDIR}/${DISTNAME}/holiday/holiday_*.orig
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/holiday/holiday_* ${X11PREFIX}/share/plan/holiday
	for f in HISTORY README; do					\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$$f ${X11PREFIX}/share/plan; \
	done

.include "../../mk/bsd.pkg.mk"
