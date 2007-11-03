# $NetBSD: Makefile,v 1.1.1.1 2007/11/03 17:27:55 rillig Exp $
#

DISTNAME=	awesome-1.3
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://awesome.naquadah.org/download/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://awesome.naquadah.org/
COMMENT=	Tiling window manager

EGDIR=		${PREFIX}/share/examples/awesome/

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/awesomerc ${EGDIR}

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
