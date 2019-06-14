# $NetBSD: Makefile,v 1.62 2019/06/14 23:10:54 gutteridge Exp $

DISTNAME=	qtwebkit-${QTWKVERSION}
PKGNAME=	qt5-qtwebkit-${QTWKVERSION:S/-/./}
PKGREVISION=	14
MASTER_SITES=	${MASTER_SITE_GITHUB:=annulen/}
GITHUB_PROJECT=	webkit
GITHUB_RELEASE=	${DISTNAME}
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qt-project.org/
COMMENT=	Qt5 WebView module
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3
EXTRACT_SUFX=	.tar.xz

QTWKVERSION=	5.212.0-alpha2

PATCHFILES=		0325d51c4a2a05fb.patch 6c7b0f61c12d28cc.patch
PATCH_SITES=		https://github.com/annulen/webkit/commit/
PATCH_DIST_STRIP=	-p1

PYTHON_VERSIONS_ACCEPTED=	27 # as of 5.212.0-alpha2

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:M*}

USE_LANGUAGES=          c c++11
USE_TOOLS+=             gmake perl:build pkg-config bison flex sed
USE_CMAKE=		yes
CMAKE_ARG_PATH=		..
CONFIGURE_DIRS=		_build
CMAKE_INSTALL_PREFIX=	${PREFIX}/qt5
TEST_TARGET=		test

CMAKE_ARGS+=		-DPORT=Qt
CMAKE_ARGS+=		-DENABLE_TOOLS=OFF
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DSHARED_CORE:BOOL=ON
CMAKE_ARGS+=		-DUSE_SYSTEM_MALLOC:BOOL=ON
CMAKE_ARGS+=		-DUSE_LD_GOLD:BOOL=OFF
## requires gcc >= 4.9
#CMAKE_ARGS+=		-DENABLE_FTL_JIT:BOOL=OFF
#CMAKE_ARGS+=		-DENABLE_INDEXED_DATABASE:BOOL=OFF
## needs JIT and ASSEMBLER
CMAKE_ARGS+=		-DENABLE_SAMPLING_PROFILER:BOOL=OFF

CMAKE_ARGS+=		-DKDE_INSTALL_LIBEXECDIR=${CMAKE_INSTALL_PREFIX}/libexec
#CMAKE_ARGS+=		-DLIBEXEC_INSTALL_DIR=${CMAKE_INSTALL_PREFIX}/libexec

GCC_REQD+=	4.9

pre-configure:
	${MKDIR} ${WRKSRC}/_build

# wcstof(3) etc. is used in C++ code.
CFLAGS.NetBSD+=         -D_NETBSD_SOURCE

## for GL_GLEXT_LEGACY with GL/gl.h error, GL_ARB_shader_objects is not defined.
#BUILDLINK_TRANSFORM+=   rm:-Wundef

PLIST_VARS+=		mac unix
.if ${OPSYS} == "Darwin"
PLIST.mac=		yes
.else
PLIST.unix=		yes
.endif

# avoid creating a .qt directory in the users home directory
SCRIPTS_ENV+=           HOME=${WRKDIR}

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

REPLACE_PERL+=		Source/WebKit2/Scripts/generate-forwarding-headers.pl

#MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.if ${_USE_CWRAPPERS} == "yes"
BUILDLINK_TRANSFORM+=	R:${WRKSRC}/lib:${QTDIR}/lib
.else
BUILDLINK_TRANSFORM+=	rpath:${WRKSRC}/lib:${QTDIR}/lib
.endif

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
LDFLAGS+=	-Wl,-no-keep-memory -Wl-reduce-memory
.endif

# 64-bit atomic ops are required
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

post-install:
.for i in Qt5WebKit.pc Qt5WebKitWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTDIR}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../databases/sqlite3/buildlink3.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../textproc/hyphen/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=			yes
.include "../../lang/python/tool.mk"
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../mk/bsd.pkg.mk"
