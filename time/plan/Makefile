# $NetBSD: Makefile,v 1.16 2004/02/18 13:33:41 jlam Exp $

DISTNAME=	plan-1.8.4
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/plan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html
COMMENT=	Schedule planner based on X/Motif

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=	YES
USE_X11BASE=	YES
ALL_TARGET=	netbsd

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
post-configure:
	${TOUCH} ${BUILDLINK_DIR}/include/varargs.h
.endif

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/plan ${PREFIX}/share/plan \
		${PREFIX}/share/plan/holiday
	${RM} -f ${WRKDIR}/${DISTNAME}/holiday/holiday_*.orig
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/holiday/holiday_* ${PREFIX}/share/plan/holiday
	for f in HISTORY README; do					\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$$f ${PREFIX}/share/plan; \
	done

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
