# $NetBSD: Makefile,v 1.20 2007/12/12 20:42:34 wiz Exp $
#

DISTNAME=	ssystem-1.6
PKGREVISION=	3
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www1.las.es/~amil/ssystem/
COMMENT=	Solar System Flyby Simulator

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

USE_TOOLS+=	flex
USE_X11BASE=	yes

MAKE_FILE=	Makefile.FreeBSD

DATA_FILES=	*.jpg *.dat ssystem.conf
DOC_FILES=	LICENSE README

INSTALLATION_DIRS=	bin

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} ssystem ${PREFIX}/bin; \
	    ${INSTALL_DATA_DIR} ${PREFIX}/share/ssystem; \
	    ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ssystem; \
	    ${INSTALL_DATA_DIR} ${PREFIX}/share/ssystem/hires; \
	    ${INSTALL_DATA} ${DATA_FILES} ${PREFIX}/share/ssystem; \
	    ${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/share/doc/ssystem; \
	    ${INSTALL_DATA} hires/README ${PREFIX}/share/ssystem/hires

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
