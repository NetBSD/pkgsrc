# $NetBSD: Makefile,v 1.28 2015/04/25 14:25:20 tnn Exp $
#

DISTNAME=	ssystem-1.6
PKGREVISION=	6
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www1.las.es/~amil/ssystem/
COMMENT=	Solar System Flyby Simulator

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	flex bison
USE_X11BASE=	yes

MAKE_FILE=	Makefile.FreeBSD

DATA_FILES=	*.jpg *.dat ssystem.conf
DOC_FILES=	LICENSE README

INSTALLATION_DIRS=	bin share/ssystem/hires share/doc/ssystem

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} ssystem ${DESTDIR}${PREFIX}/bin; \
	    ${INSTALL_DATA} ${DATA_FILES} ${DESTDIR}${PREFIX}/share/ssystem; \
	    ${INSTALL_DATA} ${DOC_FILES} ${DESTDIR}${PREFIX}/share/doc/ssystem; \
	    ${INSTALL_DATA} hires/README ${DESTDIR}${PREFIX}/share/ssystem/hires

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
