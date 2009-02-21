# $NetBSD: Makefile,v 1.1.1.1 2009/02/21 15:15:29 wiz Exp $
#

DISTNAME=	scrotwm-0.9.1
CATEGORIES=	wm
MASTER_SITES=	http://www.peereboom.us/scrotwm/snapshot/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.peereboom.us/scrotwm/html/scrotwm.html
COMMENT=	Small dynamic tiling window manager for X11

BUILDLINK_TRANSFORM+=	rm:-Werror
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/scrotwm

post-extract:
	${MV} ${WRKSRC}/linux/linux.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scrotwm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/scrotwm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/*.conf ${DESTDIR}${PREFIX}/share/examples/scrotwm
	${INSTALL_DATA} ${WRKSRC}/*.sh ${DESTDIR}${PREFIX}/share/examples/scrotwm

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
