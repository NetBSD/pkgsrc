# $NetBSD: Makefile,v 1.38 2019/07/24 20:31:43 rhialto Exp $
#

DISTNAME=	ctwm-4.0.3
CATEGORIES=	x11 wm
MASTER_SITES=	http://ctwm.org/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	http://ctwm.org/
COMMENT=	Window manager with support for multiple virtual screens and EWMH
LICENSE=	mit

USE_CMAKE=	YES

.include "../../mk/bsd.prefs.mk"

# We need an m4 that understands the -s option.
.if !empty(TOOLS_PLATFORM.m4)
.  if !empty(:!${ECHO} yes | ${TOOLS_PLATFORM.m4} -s 2>/dev/null||${ECHO}!)
TOOLS_PLATFORM.gm4?=	${TOOLS_PLATFORM.m4}
.  endif
.endif
USE_TOOLS+=		gm4:run
AUTO_MKDIRS=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

# If M4_CMD is not set, it is autodetected as ${WRKDIR}/.tools/bin/m4
CMAKE_ARGS+=		-DM4_CMD=${TOOLS_PATH.gm4}
CMAKE_ARG_PATH=		${WRKSRC}

CONFIGURE_DIRS=		build
BUILD_DIRS=		build

pre-configure:
	${MKDIR} ${WRKSRC}/build

pre-install:
.for f in system.ctwmrc
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/ctwm/
.endfor
.for f in example.ctwmrc levitte.ctwmrc peterc.ctwmrc
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}${PREFIX}/share/examples/ctwm/
.endfor
	${INSTALL_DATA} ${FILESDIR}/ctwm.desktop \
	    ${DESTDIR}${PREFIX}/share/xsessions/ctwm.desktop

# The build optionally uses these, if found:
#BUILD_DEPENDS+=    asciidoc-[0-9]*:../../textproc/asciidoc
#BUILD_DEPENDS+=    xmlto-[0-9]*:../../textproc/xmlto
#BUILD_DEPENDS+=    doxygen-[0-9]*:../../devel/doxygen
#BUILD_DEPENDS+=    dblatex-[0-9]*:../../textproc/dblatex

# but for consistent builds, we disable them entirely.
CMAKE_ARGS+=		-DASCIIDOCTOR=
CMAKE_ARGS+=		-DASCIIDOC=
CMAKE_ARGS+=		-DA2X=
CMAKE_ARGS+=		-DXMLTO=
CMAKE_ARGS+=		-DDBLATEX=

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
