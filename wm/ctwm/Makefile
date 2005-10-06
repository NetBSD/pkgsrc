# $NetBSD: Makefile,v 1.15 2005/10/06 17:28:41 reed Exp $
#

DISTNAME=	ctwm-3.7
CATEGORIES=	x11 wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://ctwm.free.lp.se/
COMMENT=	Window manager with support for multiple virtual screens and Gnome 1.x

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_IMAKE=	YES

pre-configure:
	( ${ECHO} 'USER_JPEGLIBDIR = -L${BUILDLINK_PREFIX.jpeg}/lib -Wl,-rpath,${BUILDLINK_PREFIX.jpeg}/lib'; \
	  ${ECHO} 'USER_JPEGINCDIR = -I${BUILDLINK_PREFIX.jpeg}/include'; \
	  ${CAT} ${WRKSRC}/Imakefile.local-template; \
	) >${WRKSRC}/Imakefile.local

EXAMPLEDIR=${PREFIX}/share/examples/ctwm

pre-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
.for f in example.ctwmrc levitte.ctwmrc peterc.ctwmrc system.ctwmrc system.ctwmrc.gnome
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLEDIR}
.endfor

.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
