# $NetBSD: Makefile,v 1.10 2004/01/20 12:28:26 agc Exp $

DISTNAME=		modeline_vfr.c
PKGNAME=		modeline-20001121
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.dkfz-heidelberg.de/spec/linux/modeline/
COMMENT=		Calculates XF86 Modelines to configure your monitor for X11R6

WRKSRC=			${WRKDIR}/modeline

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
