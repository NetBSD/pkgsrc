# $NetBSD: Makefile,v 1.7 2017/08/01 17:40:17 wiz Exp $
#

DISTNAME=		fluxter-0.1.0
CATEGORIES=		wm x11
MASTER_SITES=		http://benedict.isomedia.com/homes/stevencooper/files/

MAINTAINER=		mj@turner.org.za
#HOMEPAGE=		http://benedict.isomedia.com/homes/stevencooper/projects/fluxter.html
COMMENT=		Workspace pager dockapp, particularly useful with Fluxbox

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

FLUXBOX_DATA=		${PREFIX}/share/fluxbox
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EXDIR=			${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR} ${EXDIR}

post-install:
	${RM} ${DESTDIR}${FLUXBOX_DATA}/README.fluxter
	${INSTALL_DATA} ${WRKSRC}/data/README.fluxter ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/fluxter.bb ${DESTDIR}${EXDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
