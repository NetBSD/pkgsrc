# $NetBSD: Makefile,v 1.7 2003/03/09 19:28:18 jschauma Exp $
#

DISTNAME=	ssystem-1.6
PKGREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	${HOMEPAGE}			# ${HOMEPAGE}/hires/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www1.las.es/~amil/ssystem/
COMMENT=	Solar System Flyby Simulator

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

USE_BUILDLINK2=	yes
USE_X11BASE=	yes

MAKEFILE=	Makefile.FreeBSD

DATA_FILES=	*.jpg *.dat ssystem.conf
DOC_FILES=	LICENSE README

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} ssystem ${X11PREFIX}/bin; \
	    ${INSTALL_DATA_DIR} ${X11PREFIX}/share/ssystem; \
	    ${INSTALL_DATA_DIR} ${X11PREFIX}/share/doc/ssystem; \
	    ${INSTALL_DATA_DIR} ${X11PREFIX}/share/ssystem/hires; \
	    ${INSTALL_DATA} ${DATA_FILES} ${X11PREFIX}/share/ssystem; \
	    ${INSTALL_DATA} ${DOC_FILES} ${X11PREFIX}/share/doc/ssystem; \
	    ${INSTALL_DATA} hires/README ${X11PREFIX}/share/ssystem/hires

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
