# $NetBSD: Makefile,v 1.5 2001/08/20 00:59:17 hubertf Exp $
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
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/plan ${PREFIX}/share/plan \
		${PREFIX}/share/plan/holiday
	${RM} -f ${WRKDIR}/${DISTNAME}/holiday/holiday_*.orig
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/holiday/holiday_* ${PREFIX}/share/plan/holiday
	for f in HISTORY README; do					\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$$f ${PREFIX}/share/plan; \
	done

.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
