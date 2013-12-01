# $NetBSD: mozilla-common.mk,v 1.5 2013/12/01 10:54:40 richard Exp $
#
# common Makefile fragment for mozilla packages based on gecko 2.0.
#
# used by mail/thunderbird/Makefile
# used by www/firefox24/Makefile

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config perl gmake autoconf213 gm4 readelf unzip zip
USE_LANGUAGES+=		c99 c++
UNLIMIT_RESOURCES+=	datasize

.include "../../mk/bsd.prefs.mk"
# gcc45-4.5.3 of lang/gcc45 does not generate proper binary,
# but gcc 4.5.4 of NetBSD 7 generates working binary.
.if !empty(MACHINE_PLATFORM:MNetBSD-5.*)
GCC_REQD+=		4.6
.  if ${MACHINE_ARCH} == "i386"
# Fix for PR pkg/48152.
CPPFLAGS+=		-march=i486
.  endif
.else
GCC_REQD+=		4.5
.endif

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}js/src/tests/update-test262.sh

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-pedantic
CONFIGURE_ARGS+=	--enable-crypto
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ARGS+=	--disable-javaxpcom
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--enable-svg
CONFIGURE_ARGS+=	--enable-mathml
CONFIGURE_ARGS+=	--enable-pango
CONFIGURE_ARGS+=	--enable-system-cairo
CONFIGURE_ARGS+=	--enable-system-pixman
CONFIGURE_ARGS+=	--with-system-libvpx
CONFIGURE_ARGS+=	--enable-system-hunspell
CONFIGURE_ARGS+=	--enable-system-ffi
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-nss
CONFIGURE_ARGS+=	--with-system-nspr
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-system-bz2
CONFIGURE_ARGS+=	--with-system-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--enable-system-sqlite
CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--disable-libnotify
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--enable-chrome-format=flat
CONFIGURE_ARGS+=	--disable-libjpeg-turbo
CONFIGURE_ARGS+=	--enable-gstreamer

CONFIGURE_ARGS+=	--disable-elf-hack
CONFIGURE_ARGS+=	--disable-elf-dynstr-gc
CONFIGURE_ARGS+=	--disable-gconf
CONFIGURE_ARGS+=	--enable-gio
CONFIGURE_ARGS+=	--enable-extensions=gio
CONFIGURE_ARGS+=	--disable-mochitest
CONFIGURE_ARGS+=	--enable-canvas
#CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--disable-installer
CONFIGURE_ARGS+=	--enable-url-classifier
#CONFIGURE_ARGS+=	--enable-startup-notification
CONFIGURE_ARGS+=	--enable-shared-js
CONFIGURE_ARGS+=	--with-system-ply
CONFIGURE_ARGS+=	--disable-icf
CONFIGURE_ARGS+=	--disable-necko-wifi

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		${MOZILLA_DIR}xpcom/build/nsXPCOMPrivate.h
SUBST_FILES.fix-paths+=		${MOZILLA_DIR}xpcom/io/nsAppFileLocationProvider.cpp
SUBST_SED.fix-paths+=		-e 's,/usr/lib/mozilla/plugins,${PREFIX}/lib/netscape/plugins,g'

CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.guess
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.sub

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

#BUILD_MAKE_FLAGS+=		MOZ_WEBRTC_IN_LIBXUL=1

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing path to python.
SUBST_FILES.python+=	media/webrtc/trunk/build/common.gypi
SUBST_SED.python+=	-e 's,<!(python,<!(${PYTHONBIN},'

PLIST_VARS+=	sps vorbis tremor glskia throwwrapper

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
PLIST.glskia=	yes
.endif

.if ${MACHINE_ARCH} != "sparc64"
# For some reasons the configure test for GCC bug 26905 still triggers on
# sparc64, which makes mozilla skip the installation of a few wrapper headers.
# Other archs end up with one additional file in the SDK headers
PLIST.throwwrapper=	yes
.endif

.if !empty(MACHINE_PLATFORM:S/i386/x86/:MLinux-*-x86*)
PLIST.sps=	yes
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-arm*) || ${OPSYS} == "DragonFly" \
    || ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
PLIST.tremor=	yes
.else
PLIST.vorbis=	yes
.endif

#
# pysqlite2 is used by xulrunner's Python virtualenv.  If pysqlite2 isn't
# installed at build time it will attempt to download it instead, so the
# problem is stealthy in a networked environment, and obvious in an
# offline environment.
#
BUILD_DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# The configure test for __thread succeeds, but later we end up with:
# dist/bin/libxul.so: undefined reference to `__tls_get_addr'
CONFIGURE_ENV+=	ac_cv_thread_keyword=no
.endif

.if ${OPSYS} == "SunOS"
# native libbz2.so hides BZ2_crc32Table
PREFER.bzip2?=	pkgsrc
.endif

.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7.17
CONFIGURE_ENV+=	ac_cv_sqlite_secure_delete=yes	# c.f. patches/patch-al
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.10.2
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=	nss>=3.15.3
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.2nb4
.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.18.3nb1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
