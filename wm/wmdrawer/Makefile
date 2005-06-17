# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:39 jlam Exp $
#

DISTNAME=		wmdrawer-0.10.5
CATEGORIES=		misc
MASTER_SITES=		http://people.easter-eggs.org/~valos/wmdrawer/

MAINTAINER=		joel@carnat.net
HOMEPAGE=		http://people.easter-eggs.org/~valos/wmdrawer/
COMMENT=		Drawer (retractable button bar) to launch applications

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmdrawer ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/wmdrawer
	${INSTALL_MAN} ${WRKSRC}/doc/wmdrawer.1x.gz ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/wmdrawerrc.example ${PREFIX}/share/examples/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/wmdrawer

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
