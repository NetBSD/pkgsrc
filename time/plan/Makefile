# $NetBSD: Makefile,v 1.19 2004/10/03 00:18:22 tv Exp $

DISTNAME=	plan-1.8.4
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/plan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.in-berlin.de/User/bitrot/plan.html
COMMENT=	Schedule planner based on X/Motif

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=	YES
USE_X11BASE=	YES
ALL_TARGET=	${LOWER_OPSYS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
ALL_TARGET=	${LOWER_VENDOR}${OS_VERSION:C/.[0-9]//}
.endif

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
post-configure:
	${TOUCH} ${BUILDLINK_DIR}/include/varargs.h
.endif

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/plan
	${INSTALL_DATA_DIR} ${PREFIX}/share/plan
	${INSTALL_DATA_DIR} ${PREFIX}/share/plan/holiday
	${RM} -f ${WRKDIR}/${DISTNAME}/holiday/holiday_*.orig
	for f in ${WRKDIR}/${DISTNAME}/holiday/holiday_*; do		\
		${INSTALL_DATA} $$f ${PREFIX}/share/plan/holiday/;	\
	done
	for f in HISTORY README; do					\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$$f ${PREFIX}/share/plan; \
	done

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
