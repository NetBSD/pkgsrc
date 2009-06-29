# $NetBSD: Makefile,v 1.11 2009/06/29 15:38:25 joerg Exp $
#

DISTNAME=		wmdrawer-0.10.5
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		http://people.easter-eggs.org/~valos/wmdrawer/

MAINTAINER=		joel@carnat.net
HOMEPAGE=		http://people.easter-eggs.org/~valos/wmdrawer/
COMMENT=		Drawer (retractable button bar) to launch applications

USE_TOOLS+=		gmake gunzip
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
DIST_SUBDIR=		${PKGNAME_NOREV}

post-build:
	gunzip ${WRKSRC}/doc/wmdrawer.1x.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmdrawer ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/wmdrawer
	${INSTALL_MAN} ${WRKSRC}/doc/wmdrawer.1x ${PREFIX}/${PKGMANDIR}/man1/wmdrawer.1
	${INSTALL_DATA} ${WRKSRC}/wmdrawerrc.example ${PREFIX}/share/examples/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/wmdrawer

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
