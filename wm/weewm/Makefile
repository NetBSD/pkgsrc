# $NetBSD: Makefile,v 1.1.1.1 2004/08/16 19:36:32 minskim Exp $
#

DISTNAME=	weewm-0.0.2
CATEGORIES=	wm
MASTER_SITES=	http://www.weewm.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.weewm.org/
COMMENT=	Fast and ultra light windowmanager with total keyboard control

USE_BUILDLINK3=		yes
USE_X11=		yes

EXAMPLESDIR=	${PREFIX}/share/examples/weewm
DOCDIR=		${PREFIX}/share/doc/weewm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/weewm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/weewm.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/config.rc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/keys.rc ${EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in AUTHORS FAQ README
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
