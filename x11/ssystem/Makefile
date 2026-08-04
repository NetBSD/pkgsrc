# $NetBSD: Makefile,v 1.37 2026/08/04 20:29:21 wiz Exp $
#

DISTNAME=	ssystem-1.6
PKGREVISION=	10
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www1.las.es/~amil/ssystem/
COMMENT=	Solar System Flyby Simulator

USE_TOOLS+=	flex bison

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
