# $NetBSD: Makefile,v 1.4 2008/04/23 22:11:27 wiz Exp $
#

DISTNAME=		awesome-2.2
CATEGORIES=		wm
MASTER_SITES=		http://awesome.naquadah.org/download/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://awesome.naquadah.org/
COMMENT=		Tiling window manager based on dwm

BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

EGDIR=			${PREFIX}/share/examples/awesome
MESSAGE_SUBST+=		EGDIR=${EGDIR}/awesomerc

USE_LANGUAGES=		c99
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/awesomerc ${DESTDIR}${EGDIR}

.include "../../devel/confuse/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
