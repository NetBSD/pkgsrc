# $NetBSD: Makefile,v 1.8 2026/03/29 16:54:28 tnn Exp $

DISTNAME=	qtwebengine-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwebengine-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 webengine module
CATEGORIES=	www
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

CMAKE_GENERATORS_INCOMPATIBLE=	make

.include "../../x11/qt6-qtbase/Makefile.common"

AUDIOIO=			kikadf-chromium-audioio-v130.0.tar.gz
DISTFILES+=			${DEFAULT_DISTFILES}
DISTFILES+=			${AUDIOIO}
SITES.${AUDIOIO}=		${MASTER_SITE_GITHUB:=kikadf/chromium-audioio/archive/v130.0.tar.gz}
EXTRACT_DIR.${AUDIOIO}=		${WRKSRC}/src/3rdparty/chromium/media/audio/audioio
EXTRACT_OPTS_TAR.${AUDIOIO}=	--strip-components=1

TOOL_DEPENDS+=		gperf>=3.2:../../devel/gperf
TOOL_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build
TOOL_DEPENDS+=		nodejs-[0-9]*:../../lang/nodejs
TOOL_DEPENDS+=		${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

USE_CXX_FEATURES=	c++20
USE_TOOLS+=		bison

UNLIMIT_RESOURCES+=	datasize

EXTRA_CXXFLAGS=		-I${BUILDLINK_DIR}/include/libepoll-shim

# kill fatal warnings or QtPdf fails to build because of
#  warning: libstdc++.so.9, needed by ... may conflict with libstdc++.so.7
BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Pdf.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6PdfQuick.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6PdfWidgets.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebEngineCore.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebEngineQuick.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebEngineQuickDelegatesQml.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebEngineWidgets.pc

.include "../../mk/bsd.prefs.mk"

CMAKE_CONFIGURE_ARGS+=		-G Ninja
CMAKE_CONFIGURE_ARGS+=		-DPython3_EXECUTABLE=${PYTHONBIN}
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_pdf_v8=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_proprietary_codecs=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_ffmpeg=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_icu=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_lcms2=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_libevent=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_libvpx=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_opus=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_minizip=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_zlib=ON
# As pkgsrc abseil is built with FORCE_CXX_STD=c++14 it is incompatible
# with chromium's bundled abseil and therefore so is pkgsrc re2
# so use bundled version
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_re2=OFF
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_kerberos=ON
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_vulkan=OFF
.if ${OPSYS} == "NetBSD"
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_audioio=ON
.endif
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
CMAKE_CONFIGURE_ARGS+=		-DQT_FEATURE_webengine_system_sndio=ON
.endif

CONFIGURE_ENV+=			NINJAFLAGS=-j${_MAKE_JOBS_N:U1}

CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/dawn/third_party/dxc/utils/buildit/build_llvm
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/nearby/src/embedded/build.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/openscreen/src/third_party/protobuf/src/google/protobuf/compiler/zip_output_unittest.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/perfetto/tools/mm_events
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/protobuf/post_process_dist.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/compiler/zip_output_unittest.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/xdg-utils/scripts/xdg-terminal
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/xdg-utils/scripts/xdg-terminal.in
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/v8/tools/cppgc/export_to_github.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/v8/tools/cppgc/test_cmake.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/v8/tools/profiling/run-llprof.sh

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	src/3rdparty/chromium/base/base_paths_posix.cc
SUBST_FILES.path+=	src/3rdparty/chromium/base/process/process_handle_openbsd.cc
SUBST_FILES.path+=	src/3rdparty/chromium/build/rust/rust_bindgen.gni
SUBST_FILES.path+=	src/3rdparty/chromium/chrome/common/chrome_paths.cc
SUBST_FILES.path+=	src/3rdparty/chromium/components/policy/core/common/policy_paths.cc
SUBST_FILES.path+=	src/3rdparty/chromium/sandbox/policy/openbsd/sandbox_openbsd.cc
SUBST_FILES.path+=	src/3rdparty/chromium/services/device/hid/hid_service_freebsd.cc
SUBST_FILES.path+=	src/3rdparty/chromium/services/device/time_zone_monitor/time_zone_monitor_linux.cc
SUBST_FILES.path+=	src/3rdparty/chromium/third_party/perfetto/src/base/utils.cc
#SUBST_FILES.path+=	src/3rdparty/chromium/ui/qt/qt.gni
SUBST_FILES.path+=	src/3rdparty/chromium/v8/tools/run-paxctl.py
SUBST_FILES.path+=	src/core/CMakeLists.txt
SUBST_FILES.path+=	src/pdf/CMakeLists.txt
SUBST_VARS.path+=	PREFIX PKG_SYSCONFBASE VARBASE QTDIR X11BASE PYTHONBIN EXTRA_CXXFLAGS

NOT_PAX_MPROTECT_SAFE+=	qt6/libexec/QtWebEngineProcess

.include "options.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -j ${_MAKE_JOBS_N:U1} ${BUILD_TARGET}

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ninja -j ${_MAKE_JOBS_N:U1} ${INSTALL_TARGET}

.include "../../archivers/minizip/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libopus/buildlink3.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
# chromium insists on using its own protobuf
# so don't include here as versions must match
#.include "../../devel/protobuf/buildlink3.mk"
#.include "../../devel/re2/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=  tool
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../sysutils/pciutils/libname.mk"
# Use -lpciutils instead of -lpci for pkgsrc.
BUILDLINK_TRANSFORM+=   l:pci:${PCIUTILS_LIBNAME}
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
# needs libxml2 built with icu option, which is not default in pkgsrc
#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.endif
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../www/qt6-qtwebchannel/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
