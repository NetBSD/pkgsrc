# $NetBSD: Makefile,v 1.2 2006/07/22 04:46:19 rillig Exp $
#

DISTNAME=		fluxter-0.1.0
CATEGORIES=		wm x11
MASTER_SITES=		http://benedict.isomedia.com/homes/stevencooper/files/

MAINTAINER=		mj@turner.org.za
HOMEPAGE=		http://benedict.isomedia.com/homes/stevencooper/projects/fluxter.html
COMMENT=		Workspace pager dockapp, particularly useful with Fluxbox

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

FLUXBOX_DATA=		${PREFIX}/share/fluxbox
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EXDIR=			${PREFIX}/share/examples/${PKGBASE}

post-install:
	${RM} ${FLUXBOX_DATA}/README.fluxter
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/data/README.fluxter ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/fluxter.bb ${EXDIR}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
