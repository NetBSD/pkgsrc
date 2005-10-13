# $NetBSD: Makefile,v 1.16 2005/10/13 20:20:55 rillig Exp $
#

DISTNAME=	ctwm-3.7
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://ctwm.free.lp.se/
COMMENT=	Window manager with support for multiple virtual screens and Gnome 1.x

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

# The Solaris m4 does not understand the -s option.
.if ${OPSYS} == "SunOS"
USE_TOOLS+=		gm4:run
EXTRA_DEFINES+=		-DPATH_TO_M4=\"${TOOLS_PATH.gm4:Q}\"
# The __EXTENSIONS__ is needed for sigjmp_buf.
EXTRA_DEFINES+=		-D__EXTENSIONS__
.else
USE_TOOLS+=		m4:run
EXTRA_DEFINES+=		-DPATH_TO_M4=\"${TOOLS_PATH.m4:Q}\"
.endif
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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
