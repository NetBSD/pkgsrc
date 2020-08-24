# $NetBSD: Makefile,v 1.17 2020/08/24 06:30:58 tnn Exp $

DISTNAME=		modeline_vfr.c
PKGNAME=		modeline-20060729
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://www.bohne-lang.de/spec/linux/modeline/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bohne-lang.de/spec/linux/modeline/
COMMENT=		Calculates XF86 Modelines to configure your monitor for X11R6

DIST_SUBDIR=		${PKGNAME_NOREV}
WRKSRC=			${WRKDIR}/modeline
INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
