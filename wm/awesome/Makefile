# $NetBSD: Makefile,v 1.3 2007/11/14 20:52:50 rillig Exp $
#

DISTNAME=		awesome-1.3
PKGREVISION=		3
CATEGORIES=		wm
MASTER_SITES=		http://awesome.naquadah.org/download/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://awesome.naquadah.org/
COMMENT=		Tiling window manager based on dwm

EGDIR=			${PREFIX}/share/examples/awesome
MESSAGE_SUBST+=		EGDIR=${EGDIR}/awesomerc

USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/awesomerc ${EGDIR}

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
