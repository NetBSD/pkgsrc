# $NetBSD: Makefile,v 1.9 2008/04/25 02:28:24 reed Exp $
#

DISTNAME=	weewm-0.0.2
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://weewm.flashtux.org/download.php
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://weewm.flashtux.org/
COMMENT=	Fast and ultra light windowmanager with total keyboard control


EXAMPLESDIR=	${PREFIX}/share/examples/weewm
DOCDIR=		${PREFIX}/share/doc/weewm

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/weewm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/weewm.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/config.rc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/keys.rc ${EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in AUTHORS FAQ README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
