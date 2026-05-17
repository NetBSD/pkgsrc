# $NetBSD: Makefile,v 1.39 2026/05/17 08:06:58 vins Exp $

DISTNAME=	plan-1.12
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	https://bitrot.de/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://me.in-berlin.de/~bitrot/plan.html
COMMENT=	Schedule planner based on X/Motif
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_TOOLS+=	yacc lex

FORCE_C_STD=	c89

LDFLAGS.SunOS+=	-lsocket -lnsl

BUILD_TARGET=	pkgsrc

INSTALLATION_DIRS=	libexec/plan ${PKGMANDIR}/man1 ${PKGMANDIR}/man4 \
			share/plan/holiday

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/holiday/holiday_*.orig
	for f in ${WRKDIR}/${DISTNAME}/holiday/holiday_*; do		\
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/plan/holiday/;	\
	done
	for f in HISTORY README; do					\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$$f ${DESTDIR}${PREFIX}/share/plan; \
	done

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
