# $NetBSD: Makefile,v 1.283 2025/04/24 14:16:06 wiz Exp $

DISTNAME=	seamonkey-${SM_VER}.source
PKGNAME=	seamonkey-${SM_VER:S/b/beta/}
PKGREVISION=	2
SM_VER=		2.53.20
CATEGORIES=	www
MASTER_SITES=	https://archive.seamonkey-project.org/releases/${SM_VER}/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.seamonkey-project.org/
COMMENT=	All-in-one Internet application suite
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	nasm>=2.13:../../devel/nasm

WRKSRC=		${WRKDIR}/${DISTNAME:S/.source//}
MOZILLA_DIR=
PLIST_SRC+=	${PLIST_SRC_DFLT}
USE_LANGUAGES+=	c c++
USE_TOOLS+=	unzip pax
USE_TOOLS+=	pkg-config perl gmake autoconf213 unzip zip

GCC_REQD+=	6

.include "../../mk/bsd.prefs.mk"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-application=comm/suite
CONFIGURE_ARGS+=	--enable-calendar
CONFIGURE_ARGS+=	--enable-irc
CONFIGURE_ARGS+=	--enable-dominspector
.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk3
.else
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-cocoa
.endif
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--disable-jemalloc
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--enable-system-ffi
CONFIGURE_ARGS+=	--with-system-nss
CONFIGURE_ARGS+=	--with-system-nspr
CONFIGURE_ARGS+=	--with-system-webp
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--disable-webrtc
CONFIGURE_ARGS+=	--enable-chrome-format=omni

CONFIGURE_ARGS+=	--disable-icf
CONFIGURE_ARGS+=	--disable-updater

# As of 2.53.16, packed_simd_2 is for Rust nightly only.
CONFIGURE_ARGS+=	--disable-rust-simd

# with files/*.rs for Rust 1.39.0
CONFIGURE_ARGS+=	--disable-stylo-build-bindgen

UNLIMIT_RESOURCES+=	datasize virtualsize

ALL_ENV+=		MOZILLA_PKG_NAME=${PKGBASE}

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}

# ERROR: Unsupported linker bfd
CONFIGURE_ARGS.Darwin+=	--enable-linker=ld64

CKSUM_CRATES+=	third_party/rust/libc/
# src/unix/bsd/netbsdlike/netbsd/other/mod.rs
CKSUMS+=	4d9f7091af8e166943ac6f42ce85558909e5b6e61325039bff7adfbcf4b90212
CKSUMS+=	30c5211b393d9314f880f63e29833785c8b55369102eec21170a0fe0fd1c4a16

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

INSTALLATION_DIRS+=	lib/seamonkey/extensions
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps

# Python 2.7 and Python 3.8 or later are required simultaneously.
PYTHON_VERSIONS_ACCEPTED=	310 39
PYTHON_FOR_BUILD_ONLY=		tool
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"

TOOL_DEPENDS+=			cbindgen>=0.24.3:../../devel/cbindgen

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=		yasm>=1.1:../../devel/yasm
.endif

# This is to work around build failures where an upstream configuration script
# is confused by having more than one approximate match to MACHINE_GNU_PLATFORM
# "i486" when attempting to select the Rust compiler target.
.if ${MACHINE_PLATFORM:MNetBSD-*-i386}
CONFIGURE_ARGS+=	--target=i586-unknown-netbsd
CONFIGURE_ARGS+=	--host=i586-unknown-netbsd
.else
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
.endif

.if ${MACHINE_ARCH} == "i386"
# This is required for SSE2 code under i386.
CFLAGS+=		-mstackrealign
.endif

CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}browser/components/loop/run-all-loop-tests.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}browser/extensions/loop/run-all-loop-tests.sh

CONFIGURE_ENV+=		CPP=${CPP:Q}
ALL_ENV+=		SHELL=${CONFIG_SHELL:Q}

# Build outside ${WRKSRC}
# Try to avoid conflict with config/makefiles/xpidl/Makefile.in
OBJDIR=			${WRKDIR}/build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

# See ${WRKSRC}/security/sandbox/mac/Sandbox.mm: On Darwin, sandboxing
# support is only available when the toolkit is cairo-cocoa.
CONFIGURE_ARGS.Darwin+=	--disable-sandbox

# The configure test for __thread succeeds, but later we end up with:
# dist/bin/libxul.so: undefined reference to `__tls_get_addr'
CONFIGURE_ENV.NetBSD+=	ac_cv_thread_keyword=no

CHECK_PORTABILITY_SKIP+=	js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=	modules/pdfium/update.sh
CHECK_PORTABILITY_SKIP+=	security/nss/tests/libpkix/libpkix.sh

CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=		lib/seamonkey/omni.ja

CONFIG_GUESS_OVERRIDE+=		ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.guess
CONFIG_SUB_OVERRIDE+=		ldap/sdks/c-sdk/config/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.sub

post-extract:
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/${MOZILLA_DIR}/media/libcubeb/src

pre-configure:
	cd ${BUILDLINK_DIR}/bin && ${LN} -sf ${PYTHONBIN} python3
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf-2.13
	${SED}	-e 's/@MOZ_APP_DISPLAYNAME@/SeaMonkey/g' \
		-e 's/@MOZ_APP_NAME@/seamonkey/g' \
		${WRKSRC}/${MOZILLA_DIR}/toolkit/mozapps/installer/linux/rpm/mozilla.desktop > \
		${WRKDIR}/seamonkey.desktop

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/seamonkey
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/seamonkey
	${ECHO} '${PREFIX}/lib/seamonkey/seamonkey "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/seamonkey
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/seamonkey
	@${STEP_MSG} "Installing bundled seamonkey extensions."
	rm -rf ${WRKDIR}/${OBJDIR}/extensions
	${MKDIR} ${WRKDIR}/${OBJDIR}/extensions
	${RUN} for e in ${XPI_FILES}; do				\
	  subdir=`${UNZIP_CMD} -c "$$e" install.rdf | awk '/^    <em:id>/ {sub(".*<em:id>","");sub("</em:id>.*","");print;exit;}'` &&	\
	  ${MKDIR} "${WRKDIR}/${OBJDIR}/extensions/$$subdir" &&			\
	  cd "${WRKDIR}/${OBJDIR}/extensions/$$subdir" &&				\
	  ${UNZIP_CMD} -aqo $$e;					\
	done
	cd ${WRKDIR}/${OBJDIR}/extensions && pax -rw .				\
	   ${DESTDIR}${PREFIX}/lib/seamonkey/extensions/.
	rm -rf ${WRKDIR}/${OBJDIR}/extensions
	${INSTALL_DATA} ${WRKDIR}/seamonkey.desktop \
		${DESTDIR}${PREFIX}/share/applications/seamonkey.desktop
.for s in 16 22 24 32 48 64 128 256
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/comm/suite/branding/seamonkey/default${s}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/seamonkey.png
.endfor

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

do-test:
	cd ${WRKSRC}/${OBJDIR}/dist/bin &&	\
	     ./run-mozilla.sh ${WRKSRC}/mach check-spidermonkey

.include "options.mk"
.include "../../mk/atomic64.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.18
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
RUST_REQ=	1.23.0
.include "../../lang/rust/rust.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.  include "../../x11/gtk3/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
