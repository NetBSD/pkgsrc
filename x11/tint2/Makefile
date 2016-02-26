# $NetBSD: Makefile,v 1.36 2016/02/26 11:27:17 jperkin Exp $

DISTNAME=		tint2-0.11
PKGREVISION=		24
CATEGORIES=		x11
MASTER_SITES=		http://tint2.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		fernandotcl@gmail.com
HOMEPAGE=		http://code.google.com/p/tint2/
COMMENT=		Tint2 is a simple panel/taskbar
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++ # XXX CMake. pkg does not really need c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS=	share/examples/tint2
OWN_DIRS=		${PKG_SYSCONFDIR}/xdg/tint2
CONF_FILES=		${PREFIX}/share/examples/tint2/tint2rc \
			${PKG_SYSCONFDIR}/xdg/tint2/tint2rc

REPLACE_PYTHON+=	src/tint2conf/tintwizard.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-gtk2

# XXX: why not use normal CMAKE_ARGS infrastructure?
CMAKE_OPTS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_OPTS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}
CMAKE_OPTS+=	-DMANDIR=${PKGMANDIR}
# Below rpath fix is copypasted from graphics/vtk.
CMAKE_OPTS+=	-DCMAKE_INSTALL_RPATH:STRING=${PREFIX}/lib:${X11BASE}/lib${LIBABISUFFIX:Q}	\
CMAKE_OPTS+=	-DCMAKE_SKIP_BUILD_RPATH:BOOL=ON		\
CMAKE_OPTS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH:BOOL=ON	\
CMAKE_OPTS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

OPSYSVARS+=		CMAKE_OPTS
CMAKE_OPTS.Linux=	-DENABLE_BATTERY=ON
CMAKE_OPTS.*=		-DENABLE_BATTERY=OFF

do-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/cmake ${CMAKE_OPTS} .

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample/tint2rc \
		${DESTDIR}${PREFIX}/share/examples/tint2

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
