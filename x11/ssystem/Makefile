# $NetBSD: Makefile,v 1.4 2001/09/27 23:19:03 jlam Exp $
#

DISTNAME=	ssystem-1.6
CATEGORIES=	x11 graphics
MASTER_SITES=	${HOMEPAGE}			# ${HOMEPAGE}/hires/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www1.las.es/~amil/ssystem/
COMMENT=	Solar System Flyby Simulator

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_MESA=	yes
USE_X11BASE=	yes

MAKEFILE=	Makefile.FreeBSD

DATA_FILES=	*.jpg *.dat ssystem.conf
DOC_FILES=	LICENSE README

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} ssystem ${X11BASE}/bin; \
	    ${INSTALL_DATA_DIR} ${X11BASE}/share/ssystem; \
	    ${INSTALL_DATA_DIR} ${X11BASE}/share/doc/ssystem; \
	    ${INSTALL_DATA_DIR} ${X11BASE}/share/ssystem/hires; \
	    ${INSTALL_DATA} ${DATA_FILES} ${X11BASE}/share/ssystem; \
	    ${INSTALL_DATA} ${DOC_FILES} ${X11BASE}/share/doc/ssystem; \
	    ${INSTALL_DATA} hires/README ${X11BASE}/share/ssystem/hires

.include "../../mk/bsd.pkg.mk"
