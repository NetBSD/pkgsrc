# $NetBSD: Makefile,v 1.9 2003/07/21 17:38:29 martti Exp $

DISTNAME=		modeline_vfr.c
PKGNAME=		modeline-20001121
WRKSRC=			${WRKDIR}/modeline
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.dkfz-heidelberg.de/spec/linux/modeline/
COMMENT=		Calculates XF86 Modelines to configure your monitor for X11R6

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
