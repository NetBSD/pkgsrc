# $NetBSD: Makefile,v 1.3 2001/02/17 17:06:36 wiz Exp $

DISTNAME=		modeline_vfr.c
PKGNAME=		modeline-20001121
CATEGORIES=		x11
MASTER_SITES=		http://www.dkfz-heidelberg.de/spec/linux/modeline/
EXTRACT_SUFX=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.dkfz-heidelberg.de/spec/linux/modeline/
COMMENT=		calculates XF86 Modelines to configure your monitor for X11R6

WRKSRC=			${WRKDIR}/modeline

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
