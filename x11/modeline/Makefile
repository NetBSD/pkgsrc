# $NetBSD: Makefile,v 1.14 2009/07/07 18:22:43 joerg Exp $

DISTNAME=		modeline_vfr.c
PKGNAME=		modeline-20001121
CATEGORIES=		x11
MASTER_SITES=		http://www.bohne-lang.de/spec/linux/modeline/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bohne-lang.de/spec/linux/modeline/
COMMENT=		Calculates XF86 Modelines to configure your monitor for X11R6

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/modeline
INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
