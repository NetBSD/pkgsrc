# $NetBSD: Makefile,v 1.4 2001/07/03 20:35:31 jlam Exp $
#

DISTNAME=	plan-1.8.4
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/plan/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html
COMMENT=	Schedule planner based on X/Motif

USE_BUILDLINK_ONLY=	YES
ALL_TARGET=		netbsd

CFLAGS+=	-I${X11BASE}/include

pre-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/libexec/plan ${X11PREFIX}/share/plan \
		${X11PREFIX}/share/plan/holiday
	${RM} -f ${WRKDIR}/${DISTNAME}/holiday/holiday_*.orig
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/holiday/holiday_* ${X11PREFIX}/share/plan/holiday
	for f in HISTORY README; do					\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$$f ${X11PREFIX}/share/plan; \
	done

.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
