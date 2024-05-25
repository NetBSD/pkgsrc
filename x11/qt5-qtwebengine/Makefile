# $NetBSD: Makefile,v 1.68 2024/05/25 14:21:22 adam Exp $
# FIXME: build fails when protobuf and abseil packages are installed.

DISTNAME=	qtwebengine-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtwebengine-${QTVERSION}
COMMENT=	Chromium-based web engine for Qt5

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

PYTHON_VERSIONS_INCOMPATIBLE=	312

BUILD_TARGET=	first
QMAKE_ARGS+=	-- -webengine-icu

USE_TOOLS+=	bison bash
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
#TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
#TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
TOOL_DEPENDS+=	nodejs>=14:../../lang/nodejs

#JPEG_ACCEPTED=	libjpeg-turbo

BUILDLINK_TRANSFORM.NetBSD+=	rm:-fgnu-inline-asm
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--fatal-warnings

MAKE_ENV+=	NINJAJOBS="-j ${_MAKE_JOBS_N:U1}"

UNLIMIT_RESOURCES+=	datasize

CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/ffmpeg/configure
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/opus/src/doc/build_draft.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/protobuf/post_process_dist.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/compiler/zip_output_unittest.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/sqlite/src/configure
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/xdg-utils/scripts/xdg-terminal
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/xdg-utils/scripts/xdg-terminal.in
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/v8/tools/cppgc/export_to_github.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/v8/tools/cppgc/test_cmake.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/v8/tools/run-llprof.sh

# These libraries are used from the system and the build infrastructure
# removes them from the bundled third_party directory and replaces them
# with hooks to use them from the system.
GN_SYSTEM_LIBS=	libevent libxslt #yasm
CHROMESRC=	${WRKSRC}/src/3rdparty/chromium

pre-configure:
	${CP} ${FILESDIR}/netbsd.pri ${WRKSRC}/src/core/config/
	${CP} ${FILESDIR}/openbsd.pri ${WRKSRC}/src/core/config/
	${CP} ${FILESDIR}/netbsd.pri ${WRKSRC}/src/buildtools/config/
	${CP} ${FILESDIR}/openbsd.pri ${WRKSRC}/src/buildtools/config/
	${MKDIR} ${CHROMESRC}/media/audio/sndio ${CHROMESRC}/media/audio/openbsd
	${CP} ${FILESDIR}/sndio_* ${CHROMESRC}/media/audio/sndio
	${CP} ${FILESDIR}/hid_* ${CHROMESRC}/services/device/hid
	${CP} ${FILESDIR}/audio_manager_openbsd.* ${CHROMESRC}/media/audio/openbsd
	cd ${WRKSRC} && env -i ${MAKE_ENV} ${CHROMESRC}/build/linux/unbundle/replace_gn_files.py \
		--system-libraries ${GN_SYSTEM_LIBS}
	# re2 pulls in abseil headers, but doesn't need them
	# avoid conflict with the ones included in the tarball
	${RM} -rf ${BUILDLINK_DIR}/include/absl

post-install:
.for i in Qt5Pdf.pc Qt5PdfWidgets.pc Qt5WebEngine.pc Qt5WebEngineCore.pc Qt5WebEngineWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor
.if ${OPSYS} == "NetBSD"
	/usr/sbin/paxctl +m ${DESTDIR}${PREFIX}/qt5/libexec/QtWebEngineProcess
.endif
.if ${OPSYS} == "Darwin"
MAKE_ENV+=	OSX_SDK_PATH=${OSX_SDK_PATH:Q}
MAKE_ENV+=	OSX_VERSION=${OSX_VERSION}
.endif

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
# chromium insists on using its own protobuf
# so don't include here as versions must match
#.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	tool
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
BUILDLINK_API_DEPENDS.pciutils+=	pciutils>=3.8
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
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
