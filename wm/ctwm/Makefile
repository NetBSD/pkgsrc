# $NetBSD: Makefile,v 1.19 2006/12/15 20:33:01 joerg Exp $
#

DISTNAME=	ctwm-3.7
PKGREVISION=	3
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
	( ${ECHO} 'USER_JPEGLIBDIR = -L${BUILDLINK_PREFIX.jpeg}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.jpeg}/lib'; \
	  ${ECHO} 'USER_JPEGINCDIR = -I${BUILDLINK_PREFIX.jpeg}/include'; \
	  ${CAT} ${WRKSRC}/Imakefile.local-template; \
	) >${WRKSRC}/Imakefile.local

EXAMPLEDIR=${PREFIX}/share/examples/ctwm

pre-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
.for f in example.ctwmrc levitte.ctwmrc peterc.ctwmrc system.ctwmrc system.ctwmrc.gnome
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLEDIR}
.endfor

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
