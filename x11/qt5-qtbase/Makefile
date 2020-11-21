# $NetBSD: Makefile,v 1.104 2020/11/21 11:22:31 adam Exp $

DISTNAME=	qtbase-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtbase-${QTVERSION}
COMMENT=	C++ X GUI toolkit

.include "../../x11/qt5-qtbase/Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix "${QTPREFIX}"
CONFIGURE_ARGS+=	-I "${PREFIX}/include"
CONFIGURE_ARGS+=	-L "${PREFIX}/lib"
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
CONFIGURE_ARGS+=	-no-sql-sqlite2
CONFIGURE_ARGS+=	-no-sql-tds
CONFIGURE_ARGS+=	-no-strip
CONFIGURE_ARGS+=	-no-tslib
CONFIGURE_ARGS+=	-no-vulkan
CONFIGURE_ARGS+=	-no-use-gold-linker
CONFIGURE_ARGS+=	-pkg-config
CONFIGURE_ARGS+=	-release
CONFIGURE_ARGS+=	-shared
CONFIGURE_ARGS+=	-system-harfbuzz
CONFIGURE_ARGS+=	-system-libjpeg
CONFIGURE_ARGS+=	-system-libpng
CONFIGURE_ARGS+=	-system-pcre
CONFIGURE_ARGS+=	-system-sqlite
CONFIGURE_ARGS+=	-system-zlib
.if defined(MAKE_JOBS)
.  if !defined(MAKE_JOBS_SAFE) || empty(MAKE_JOBS_SAFE:M[nN][oO])
CONFIGURE_ENV+=		MAKEFLAGS=-j${MAKE_JOBS}
.  endif
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	-fontconfig
QMAKE_CONF=		qmake.conf
.  if ${OPSYS} != "SunOS" && \
      (!empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64))
CONFIGURE_ARGS+=	-reduce-relocations
.  endif
.else
CONFIGURE_ARGS+=	-no-rpath	# avoid @rpath in dylibs
QMAKE_CONF=		qmake.conf.mac
.endif

PLIST_VARS+=		egl

.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS"
.  if !empty(PKGSRC_COMPILER:Mgcc) || !empty(PKGSRC_COMPILER:Mclang)
.    if ${ABI:U} == "64"
CONFIGURE_ARGS+=		-platform solaris-g++-64
.    else
CONFIGURE_ARGS+=		-platform solaris-g++
.    endif
.  else
.    if ${ABI:U} == "64"
CONFIGURE_ARGS+=		-platform solaris-cc-64
.    else
CONFIGURE_ARGS+=		-platform solaris-cc
.    endif
.  endif
NETWORK_LIBS=			-lsocket -lnsl
.elif ${OPSYS} == "Interix"
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
CONFIGURE_ARGS+=	-I "$$(xcrun --show-sdk-path)"/usr/include
.  endif
.  if exists(/usr/lib/libresolv.dylib)
LDFLAGS+=			-lresolv
.  endif
.elif ${OPSYS} == "Linux"
LDFLAGS+=			-ldl
.elif ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
.  if exists(/usr/lib/libexecinfo.so)
LDFLAGS+=			-lexecinfo
.  endif
LDFLAGS.FreeBSD+=		-lutil
.endif

REPLACE_PERL+=		bin/fixqt4headers.pl
REPLACE_PERL+=		bin/syncqt.pl
REPLACE_PERL+=		mkspecs/features/data/unix/findclasslist.pl

PTHREAD_OPTS+=		require
UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+=	${QTPREFIX}

BUILD_TARGET=		sub-src
INSTALLATION_DIRS=	${QTPREFIX}/bin lib/pkgconfig
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/echoplugin/echoplugin.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/echoplugin/plugin/plugin.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/plugandpaint/plugandpaint.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/plugandpaintplugins/basictools/basictools.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/plugandpaintplugins/extrafilters/extrafilters.pro
CHECK_INTERPRETER_SKIP+=	qt5/examples/widgets/tools/styleplugin/plugin/plugin.pro
CHECK_INTERPRETER_SKIP+=	qt5/mkspecs/features/data/mac/objc_namespace.sh
CHECK_INTERPRETER_SKIP+=	qt5/mkspecs/features/uikit/device_destinations.sh
CHECK_INTERPRETER_SKIP+=	qt5/mkspecs/features/uikit/devices.py
CHECK_INTERPRETER_SKIP+=	qt5/mkspecs/macx-ios-clang/rename_main.sh

SUBST_CLASSES+=		opt
SUBST_STAGE.opt=	pre-configure
SUBST_MESSAGE.opt=	Removing some Qt5 default compiler flags.
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
SUBST_VARS.path=	PREFIX

BROKEN_FILES=		qt5/mkspecs/modules/qt_lib_bootstrap_private.pri
BROKEN_FILES1=		qt5/mkspecs/qmodule.pri

PC_FILES=		Qt5Concurrent.pc Qt5Core.pc \
			Qt5Gui.pc Qt5Network.pc Qt5OpenGL.pc \
			Qt5OpenGLExtensions.pc \
			Qt5PrintSupport.pc Qt5Sql.pc Qt5Test.pc \
			Qt5Widgets.pc Qt5Xml.pc

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
			cp ${WRKSRC}/qmake.conf $${dir}; \
			rm -f $${dir}/*.orig; \
		done
	${RM} -f ${WRKSRC}/mkspecs/features/mac/default_pre.prf
	${RM} -f ${WRKSRC}/mkspecs/features/mac/default_post.prf

.include "options.mk"

post-install:
.for i in ${PC_FILES}
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor
	cd ${WRKSRC} && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_mkspecs
# The pri file has WRKSRC in it.
	${SED} -e 's,${WRKSRC}/bin/qmake,${QTDIR}/bin/qmake,g' \
		${DESTDIR}${PREFIX}/${BROKEN_FILES} \
		> ${DESTDIR}${PREFIX}/${BROKEN_FILES}.1
	${MV} -f ${DESTDIR}${PREFIX}/${BROKEN_FILES}.1 \
		${DESTDIR}${PREFIX}/${BROKEN_FILES}
	${SED} -e 's,PKG_CONFIG_EXECUTABLE = .*,PKG_CONFIG_EXECUTABLE = ${TOOLS_PATH.pkg-config},' \
		${DESTDIR}${PREFIX}/${BROKEN_FILES1} \
		> ${DESTDIR}${PREFIX}/${BROKEN_FILES1}.1
	${MV} -f ${DESTDIR}${PREFIX}/${BROKEN_FILES1}.1 \
		${DESTDIR}${PREFIX}/${BROKEN_FILES1}

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
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.  if !empty(MESALIB_SUPPORTS_EGL:Myes)
PLIST.egl=	yes
.  endif
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.11
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
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
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
