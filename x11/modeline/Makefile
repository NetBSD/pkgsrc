# $NetBSD: Makefile,v 1.2 2000/11/28 20:50:08 tron Exp $

DISTNAME=		modeline_vfr.c
PKGNAME=		modeline-20001121
CATEGORIES=		x11
MASTER_SITES=		http://www.dkfz-heidelberg.de/spec/linux/modeline/
EXTRACT_SUFX=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.dkfz-heidelberg.de/spec/linux/modeline/

WRKSRC=			${WRKDIR}/modeline

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
