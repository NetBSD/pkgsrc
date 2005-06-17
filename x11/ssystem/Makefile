# $NetBSD: Makefile,v 1.14 2005/06/17 04:49:49 jlam Exp $
#

DISTNAME=	ssystem-1.6
PKGREVISION=	2
CATEGORIES=	x11 graphics
MASTER_SITES=	${HOMEPAGE}			# ${HOMEPAGE}/hires/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www1.las.es/~amil/ssystem/
COMMENT=	Solar System Flyby Simulator

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

USE_X11BASE=	yes

MAKEFILE=	Makefile.FreeBSD

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
