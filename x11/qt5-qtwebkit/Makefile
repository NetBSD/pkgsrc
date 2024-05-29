# $NetBSD: Makefile,v 1.123 2024/05/29 16:35:13 adam Exp $

QTWKVERSION=	5.212.0-alpha4
DISTNAME=	qtwebkit-${QTWKVERSION}
PKGNAME=	qt5-qtwebkit-${QTWKVERSION:S/-/./}
PKGREVISION=	27
CATEGORIES=	x11 www
MASTER_SITES=	${MASTER_SITE_GITHUB:=qtwebkit/}
GITHUB_PROJECT=	qtwebkit
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/qtwebkit/qtwebkit/wiki
COMMENT=	Qt5 WebView module
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LANGUAGES=		c c++11
USE_TOOLS+=		bison perl:build pkg-config
CMAKE_INSTALL_PREFIX=	${QTDIR}
CMAKE_INSTALL_NAME_DIR=	${QTDIR}/lib
TEST_TARGET=		test

# Source/JavaScriptCore/offlineasm/parser.rb:587:in `block in parseSequence': undefined method `=~'
RUBY_VERSIONS_ACCEPTED=		31

CMAKE_ARGS+=	-DPORT=Qt
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DENABLE_API_TESTS=OFF
CMAKE_ARGS+=	-DENABLE_TOOLS=OFF
CMAKE_ARGS+=	-DKDE_INSTALL_LIBEXECDIR=${QTDIR}/libexec
CMAKE_ARGS+=	-DSHARED_CORE=ON
CMAKE_ARGS+=	-DUSE_LD_GOLD=OFF
CMAKE_ARGS+=	-DUSE_SYSTEM_MALLOC=ON
# for Darwin
CMAKE_ARGS+=	-DMACOS_BUILD_FRAMEWORKS=OFF
CMAKE_ARGS+=	-DMACOS_FORCE_SYSTEM_XML_LIBRARIES=OFF
CMAKE_ARGS+=	-DMACOS_USE_SYSTEM_ICU=OFF

UNLIMIT_RESOURCES+=	cputime

GCC_REQD+=	4.9

# wcstof(3) etc. is used in C++ code.
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

# temporary fix for GLib 2.68 breakage
# https://gitlab.gnome.org/GNOME/glib/-/merge_requests/1963
CXXFLAGS+=		-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_66

# avoid creating a .qt directory in the users home directory
SCRIPTS_ENV+=		HOME=${WRKDIR}

REPLACE_PERL+=		Source/WebKit2/Scripts/generate-forwarding-headers.pl

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

.if ${_USE_CWRAPPERS} == "yes"
BUILDLINK_TRANSFORM+=	R:${WRKSRC}/lib:${QTDIR}/lib
.else
BUILDLINK_TRANSFORM+=	rpath:${WRKSRC}/lib:${QTDIR}/lib
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--gc-sections

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH:M*arm*}
LDFLAGS+=	-Wl,--no-keep-memory
.endif

.if ${OPSYS} == "SunOS"
CMAKE_ARGS+=	-DUSE_LINKER_VERSION_SCRIPT=OFF
LDFLAGS+=	-lsocket -lnsl
.endif

# JavaScriptCore requires at least MIPS32.
.if ${MACHINE_ARCH:Mmips64*}
CFLAGS+=	-march=mips64
.elif ${MACHINE_ARCH:Mmips*}
CFLAGS+=	-march=mips32
.endif

post-install:
.for i in Qt5WebKit.pc Qt5WebKitWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTDIR}/lib/pkgconfig/${i} ${i}
.endfor

# Not supported on Win and Mac.
# See comment in Source/WebKit2/PlatformQt.cmake
PLIST_VARS+=	npapi

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../fonts/woff2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/hyphen/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
PLIST.npapi=	yes
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	tool
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
