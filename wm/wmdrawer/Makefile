# $NetBSD: Makefile,v 1.13 2009/12/17 19:50:27 abs Exp $
#

DISTNAME=		wmdrawer-0.10.5
PKGREVISION=		4
CATEGORIES=		misc
MASTER_SITES=		http://people.easter-eggs.org/~valos/wmdrawer/

MAINTAINER=		joel@carnat.net
HOMEPAGE=		http://people.easter-eggs.org/~valos/wmdrawer/
COMMENT=		Drawer (retractable button bar) to launch applications

USE_TOOLS+=		gmake gunzip
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/wmdrawer share/examples/wmdrawer
PKG_DESTDIR_SUPPORT=	user-destdir
DIST_SUBDIR=		${PKGNAME_NOREV}

post-build:
	gunzip ${WRKSRC}/doc/wmdrawer.1x.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmdrawer ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/wmdrawer.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wmdrawer.1
	${INSTALL_DATA} ${WRKSRC}/wmdrawerrc.example ${DESTDIR}${PREFIX}/share/examples/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/wmdrawer
	${INSTALL_DATA} ${WRKSRC}/TODO ${DESTDIR}${PREFIX}/share/doc/wmdrawer

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
