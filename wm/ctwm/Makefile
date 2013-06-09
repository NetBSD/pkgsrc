# $NetBSD: Makefile,v 1.31 2013/06/09 15:26:45 ryoon Exp $
#

DISTNAME=	ctwm-3.8.1
CATEGORIES=	x11 wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://ctwm.free.lp.se/
COMMENT=	Window manager with support for multiple virtual screens and Gnome 1.x

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

# We need an m4 that understands the -s option.
USE_TOOLS+=		gm4:run
OPSYSVARS+=		EXTRA_DEFINES
EXTRA_DEFINES+=		-DPATH_TO_M4=\"${TOOLS_PATH.gm4:Q}\"
# The __EXTENSIONS__ is needed for sigjmp_buf.
EXTRA_DEFINES.SunOS+=	-D__EXTENSIONS__
MAKE_ENV+=		EXTRA_DEFINES=${EXTRA_DEFINES:Q}

pre-configure:
	( ${ECHO} 'USER_JPEGLIBDIR = -L${JPEGBASE}/lib ${COMPILER_RPATH_FLAG}${JPEGBASE}/lib'; \
	  ${ECHO} 'USER_JPEGINCDIR = -I${JPEGBASE}/include'; \
	  ${CAT} ${WRKSRC}/Imakefile.local-template; \
	) >${WRKSRC}/Imakefile.local

EXAMPLEDIR=${PREFIX}/share/examples/ctwm

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLEDIR}
.for f in example.ctwmrc levitte.ctwmrc peterc.ctwmrc system.ctwmrc system.ctwmrc.gnome
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EXAMPLEDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${FILESDIR}/ctwm.desktop \
	    ${DESTDIR}${PREFIX}/share/xsessions/ctwm.desktop

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
