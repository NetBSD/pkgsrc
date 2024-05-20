# $NetBSD: Makefile,v 1.33 2024/05/20 19:38:24 adam Exp $

DISTNAME=	qtbase-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtbase-${QTVERSION}
COMMENT=	C++ X GUI toolkit
CATEGORIES=	x11

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix "${QTPREFIX}"
CONFIGURE_ARGS+=	-I "${PREFIX}/include"
CONFIGURE_ARGS+=	-L "${PREFIX}/lib"
CONFIGURE_ARGS+=	-cmake-use-default-generator
CONFIGURE_ARGS+=	-opensource -confirm-license
CONFIGURE_ARGS+=	-sysconfdir "${PKG_SYSCONFDIR}/xdg"
CONFIGURE_ARGS+=	-accessibility
CONFIGURE_ARGS+=	-icu
CONFIGURE_ARGS+=	-libproxy
CONFIGURE_ARGS+=	-openssl-linked
CONFIGURE_ARGS+=	-nomake examples
CONFIGURE_ARGS+=	-nomake tests
CONFIGURE_ARGS+=	-no-pch
CONFIGURE_ARGS+=	-no-sql-db2
CONFIGURE_ARGS+=	-no-sql-ibase
CONFIGURE_ARGS+=	-no-sql-mysql
CONFIGURE_ARGS+=	-no-sql-oci
CONFIGURE_ARGS+=	-no-sql-odbc
CONFIGURE_ARGS+=	-no-sql-psql
CONFIGURE_ARGS+=	-no-strip
CONFIGURE_ARGS+=	-no-tslib
CONFIGURE_ARGS+=	-no-vulkan
CONFIGURE_ARGS+=	-no-use-gold-linker
CONFIGURE_ARGS+=	-pkg-config
CONFIGURE_ARGS+=	-qt-publicsuffix
CONFIGURE_ARGS+=	-release
CONFIGURE_ARGS+=	-shared
CONFIGURE_ARGS+=	-system-doubleconversion
CONFIGURE_ARGS+=	-system-harfbuzz
CONFIGURE_ARGS+=	-system-libjpeg
CONFIGURE_ARGS+=	-system-libmd4c
CONFIGURE_ARGS+=	-system-libpng
CONFIGURE_ARGS+=	-system-pcre
CONFIGURE_ARGS+=	-system-sqlite
CONFIGURE_ARGS+=	-system-zlib
CONFIGURE_ARGS+=	-avoid_cmake_archiving_api
CONFIGURE_ARGS+=	-no-bundled-xcb-xinput

USE_TOOLS+=		bash:run

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	-fontconfig
QMAKE_CONF=		qmake.conf
.  if ${OPSYS} != "SunOS" && \
      (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	-reduce-relocations
.  endif
.else
CONFIGURE_ARGS+=	-no-rpath	# avoid @rpath in dylibs
QMAKE_CONF=		qmake.conf.mac
.endif

PLIST_VARS+=	egl egldevice x11

.include "../../mk/compiler.mk"

.if ${OPSYS} == "Interix"
CONFIGURE_ARGS+=		-platform interix-g++
CFLAGS+=			-I/usr/local/include/bind
LDFLAGS+=			-L/usr/local/lib/bind -lbind
BUILDLINK_PASSTHRU_DIRS+=	/usr/local/include/bind /usr/local/lib/bind
SYS_LIBS=			-lbind -ldb -ldl
.elif ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=		-platform freebsd-g++
LDFLAGS+=			-lexecinfo
.elif ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=		-platform macx-clang
CONFIGURE_ARGS+=		-no-framework
# pkgsrc has a patch to avoid using SDK, but the configure
# logic gets confused if it can't find the header files
# so give it a direct path to them if they aren't installed
# in /usr/include
.  if !exists(/usr/include)
CONFIGURE_ARGS+=		-I ${OSX_SDK_PATH}/usr/include
.  endif
.  if exists(/usr/lib/libresolv.dylib)
LDFLAGS+=			-lresolv
.  endif
# -lexecinfo is bundled in libc
.  if exists(${OSX_SDK_PATH}/usr/include/execinfo.h)
BUILDLINK_TRANSFORM+=		rm:-lexecinfo
.  endif
.elif ${OPSYS} == "Linux"
LDFLAGS+=			-ldl
.elif ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
.  if exists(/usr/lib/libexecinfo.so)
LDFLAGS+=			-lexecinfo
.  endif
LDFLAGS.FreeBSD+=		-lutil
.elif ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=		-no-inotify
.endif

#
# Qt uses FP16 intrinsics, but GCC isn't inserting libgcc due to it being in
# a shared library.  This isn't ideal but adding it via the usual variables
# is proving to be difficult as they are placed before the object files.
#
.if ${OPSYS} == "SunOS"
CWRAPPERS_APPEND.cc+=	-lgcc
CWRAPPERS_APPEND.cxx+=	-lgcc
.endif

REPLACE_PERL+=		libexec/syncqt.pl
REPLACE_PERL+=		mkspecs/features/data/unix/findclasslist.pl
REPLACE_BASH+=		util/android/android_emulator_launcher.sh
REPLACE_PYTHON+=	util/testrunner/sanitizer-testrunner.py
REPLACE_PYTHON+=	util/testrunner/qt-testrunner.py

PTHREAD_OPTS+=		require
UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+=	${QTPREFIX}

CHECK_INTERPRETER_SKIP+=	qt6/mkspecs/features/data/mac/objc_namespace.sh
CHECK_INTERPRETER_SKIP+=	qt6/mkspecs/features/uikit/device_destinations.sh
CHECK_INTERPRETER_SKIP+=	qt6/mkspecs/features/uikit/devices.py

SUBST_CLASSES+=		opt
SUBST_STAGE.opt=	pre-configure
SUBST_MESSAGE.opt=	Removing some Qt6 default compiler flags.
SUBST_FILES.opt=	mkspecs/common/gcc-base.conf
SUBST_SED.opt=		-e 's,-O[s23],,'

SUBST_CLASSES.SunOS+=	vscript
SUBST_STAGE.vscript=	pre-configure
SUBST_FILES.vscript=	mkspecs/common/gcc-base-unix.conf
SUBST_SED.vscript=	-e '/QMAKE_LFLAGS_VERSION_SCRIPT/d'

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Add to default XDG path.
SUBST_FILES.path=	src/corelib/io/qstandardpaths_unix.cpp
SUBST_VARS.path=	PREFIX PKG_SYSCONFBASE

# The pri file has WRKSRC in it.
SUBST_CLASSES+=		pkgconf
SUBST_STAGE.pkgconf=	post-build
SUBST_MESSAGE.pkgconf=	Fixing pkg-config WRKSRC path.
SUBST_FILES.pkgconf=	mkspecs/qmodule.pri
SUBST_SED.pkgconf=	-e 's,PKG_CONFIG_EXECUTABLE = .*,PKG_CONFIG_EXECUTABLE = ${TOOLS_PATH.pkg-config},'

.if ${OPSYS} == "Linux"
QMAKE_EXTRA=		QMAKE_PLATFORM += linux
.else
QMAKE_EXTRA=
.endif

COMPILER=	gcc
.if !empty(PKGSRC_COMPILER:Mclang)
COMPILER+=	clang llvm
.endif

pre-configure:
	${SED}  -e 's:@PREFIX@:${PREFIX}:g' \
		-e 's:@X11BASE@:${X11BASE}:g' \
		-e 's:@COMPILER@:${COMPILER:Q}:g' \
		-e 's:@CC@:${CC:Q}:g' \
		-e 's:@CXX@:${CXX:Q}:g' \
		-e 's:@LDFLAGS@:${LDFLAGS:Q}:g' \
		-e 's:@CFLAGS@:${CFLAGS:Q}:g' \
		-e 's:@CXXFLAGS@:${CXXFLAGS:Q}:g' \
		-e 's:@NETWORK_LIBS@:${NETWORK_LIBS:Q}:g' \
		-e 's:@SYS_LIBS@:${SYS_LIBS:Q}:g' \
		-e 's:@LEX@:${LEX}:g' \
		-e 's:@YACC@:${TOOLS_CMDLINE_YACC:Q}:g' \
		-e 's:@AR@:${AR:Q}:g' \
		-e 's:@MKDIR@:${MKDIR}:g' \
		-e 's:@LIBQT@:${LIBQT:Q}:g' \
		-e 's:@PTHREAD_LDFLAGS@:${PTHREAD_LDFLAGS:Q}:g' \
		-e 's:@PTHREAD_LIBS@:${PTHREAD_LIBS:Q}:g' \
		-e 's:@COMPILER_RPATH_FLAG@:${COMPILER_RPATH_FLAG}:g' \
		-e 's:@QMAKE_RANLIB@:${RANLIB}:g' \
		-e 's:@QMAKE_EXTRA@:${QMAKE_EXTRA:Q}:g' \
		${FILESDIR}/${QMAKE_CONF} > ${WRKSRC}/qmake.conf
	for dir in ${WRKSRC}/mkspecs/*; do \
		${CP} ${WRKSRC}/qmake.conf $${dir}; \
		${RM} -f $${dir}/*.orig; \
	done
	${RM} -f ${WRKSRC}/mkspecs/features/mac/default_pre.prf
	${RM} -f ${WRKSRC}/mkspecs/features/mac/default_post.prf

.include "options.mk"

CMAKE_CONFIGURE_ARGS+=	-DQT_DISABLE_RPATH:BOOL=ON

.include "../../devel/cmake/configure-settings.mk"

CONFIGURE_ARGS+=	-- ${CMAKE_CONFIGURE_ARGS}
.if ${OPSYS} != "Darwin"
LDFLAGS+=		${COMPILER_RPATH_FLAG}${QTPREFIX}/lib
.else
CMAKE_INSTALL_NAME_DIR=	${QTPREFIX}/lib
.endif

TOOL_DEPENDS+=	xmlstarlet-[0-9]*:../../textproc/xmlstarlet

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Concurrent.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Core.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Gui.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Network.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6OpenGL.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6OpenGLWidgets.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6PrintSupport.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Sql.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Test.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Widgets.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Xml.pc

.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../security/libb2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/md4c/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.if ${OPSYS} != "Darwin"
PLIST.x11=	yes
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.  if !empty(MESALIB_SUPPORTS_EGL:Myes)
PLIST.egl=	yes
.    if exists(${X11BASE}/include/EGL/eglext.h)
EGL_EXT_FILE=	cat ${X11BASE}/include/EGL/eglext.h
.      if !empty(EGL_EXT_FILE:sh:MEGL_DRM_MASTER_FD_EXT)
PLIST.egldevice=	yes
.      endif
.    endif
.  endif
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.11
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
