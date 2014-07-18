# $NetBSD: Makefile,v 1.33 2014/07/18 10:40:48 obache Exp $
#

DISTNAME=	ctwm-3.8.2
CATEGORIES=	x11 wm
MASTER_SITES=	http://ctwm.org/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://ctwm.org/
COMMENT=	Window manager with support for multiple virtual screens and Gnome 1.x
LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

# We need an m4 that understands the -s option.
.if !empty(TOOLS_PLATFORM.m4)
.  if !empty(:!${ECHO} yes | ${TOOLS_PLATFORM.m4} -s 2>/dev/null||${ECHO}!)
TOOLS_PLATFORM.gm4?=	${TOOLS_PLATFORM.m4}
.  endif
.endif
USE_TOOLS+=		gm4:run
OPSYSVARS+=		EXTRA_DEFINES
# The __EXTENSIONS__ is needed for sigjmp_buf.
EXTRA_DEFINES.SunOS+=	-D__EXTENSIONS__
MAKE_ENV+=		EXTRA_DEFINES=${EXTRA_DEFINES:Q}
AUTO_MKDIRS=		yes

pre-configure:
	( ${ECHO} 'USER_JPEGLIBDIR = -L${JPEGBASE}/lib ${COMPILER_RPATH_FLAG}${JPEGBASE}/lib'; \
	  ${ECHO} 'USER_JPEGINCDIR = -I${JPEGBASE}/include'; \
	  ${CAT} ${WRKSRC}/Imakefile.local-template; \
	  ${ECHO} '#undef M4_CMD'; \
	  ${ECHO} '#define M4_CMD ${TOOLS_PATH.gm4}'; \
	) >${WRKSRC}/Imakefile.local

pre-install:
.for f in example.ctwmrc levitte.ctwmrc peterc.ctwmrc system.ctwmrc system.ctwmrc.gnome
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/ctwm/
.endfor
	${INSTALL_DATA} ${FILESDIR}/ctwm.desktop \
	    ${DESTDIR}${PREFIX}/share/xsessions/ctwm.desktop

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
