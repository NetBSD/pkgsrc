# $NetBSD: Makefile,v 1.43 2020/06/14 15:33:28 nia Exp $

DISTNAME=	cliqz-1.36.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliqz-oss/}
GITHUB_PROJECT=	browser-f
DISTFILES=	adult-domains.bin \
		cliqz@cliqz.com.xpi \
		dat@cliqz.com.xpi \
		https-everywhere@cliqz.com.xpi \
		gdprtool@cliqz.com.xpi \
		${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAME_NOREV}

CLIQZ_CHANNEL=		release
# If the PKGVERSION_NOREV is updated, make sure to update the last build id from
# ftp -Vo - https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/lastbuildid
CLIQZ_LAST_BUILD_ID=	20200512121102
CLIQZ_PLUGIN_SUFX=	@cliqz.com.xpi

SITES.adult-domains.bin= \
	https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/
SITES.cliqz${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/
SITES.dat${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/
SITES.https-everywhere${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/
SITES.gdprtool${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${PKGVERSION_NOREV}/${CLIQZ_LAST_BUILD_ID}/

EXTRACT_USING=	bsdtar
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://cliqz.com/en/desktop
COMMENT=	Secure browser (Mozilla based) with built-in quick search
LICENSE=	mpl-2.0 AND gnu-gpl-v2

USE_TOOLS+=	pkg-config perl gmake autoconf213 unzip zip bash pax
# cliqz (which is based on firefox) needs a compiler that supports
# gnu++14 and gnu++17.  However, passing --std=gnu++17 (from wrappers,
# as a result of USE_LANGUAGES), results in problems for some Rust
# modules (as of 74.0).  Therefore, do not declare the languages that
# are actually needed.
# \todo In pkgsrc infrastructure, separate the concept of needing a
# compiler that can implement a standard, and the concept of forcibly
# adding a --std flag.  (The build system of a package should be
# setting the --std flag that is needed, rather than relying on the
# defaults of a particular compiler version.)
# NB: Even when building cliqz (which is based on firefox) with
# PKGSRC_COMPILER=gcc, the package will depend on and use clang, doing
# so outside the normal compiler selection framework.
USE_LANGUAGES+=	c99 c++

# Build script does not support python 3.x yet.
# https://firefox-source-docs.mozilla.org/build/buildsystem/python.html
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool
TOOL_DEPENDS+=			cbindgen>=0.13.1:../../devel/cbindgen
TOOL_DEPENDS+=			nodejs-[0-9]*:../../lang/nodejs

# Depend on Python3 sqlite3 module.
.if !empty(PYTHON_VERSION_DEFAULT:M3[6789])
BUILD_DEPENDS+=			py${PYTHON_VERSION_DEFAULT}-sqlite3-[0-9]*:../../databases/py-sqlite3
.else
BUILD_DEPENDS+=			py37-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif
# XXX: For now depend on python 2.7 version of sqlite3 since cliqz
# cannot detect py37-sqlite3 correctly.
BUILD_DEPENDS+=			py27-sqlite3-[0-9]*:../../databases/py-sqlite3
BUILD_DEPENDS+=			yasm>=1.1:../../devel/yasm
BUILD_DEPENDS+=			nasm>=1.1:../../devel/nasm

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

CLIQZ_ICON=		cliqz.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/cliqz/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop

MAKE_ENV+=	CQZ_RELEASE_CHANNEL=${CLIQZ_CHANNEL}
MAKE_ENV+=	CQZ_BUILD_ID=${CLIQZ_LAST_BUILD_ID}
MAKE_ENV+=	MOZBUILD_STATE_PATH=${WRKDIR}/.home/.mozbuild

.include "mozilla-common.mk"
.include "options.mk"

CHECK_WRKREF_SKIP+=	lib/cliqz/chrome/toolkit/content/global/buildconfig.html

REPLACE_BASH+=	magic_build_and_package.sh

CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/cliqz ${COMPILER_RPATH_FLAG}${PREFIX}/lib

# Needed by the Javascript JIT used in cliqz
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz-bin
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/plugin-container

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/adult-domains.bin ${WRKSRC}
	${MKDIR} ${WRKSRC}/obj/dist/bin/browser/features
	${CP} ${DISTDIR}/${DIST_SUBDIR}/cliqz${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/${DIST_SUBDIR}/dat${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/${DIST_SUBDIR}/https-everywhere${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/${DIST_SUBDIR}/gdprtool${CLIQZ_PLUGIN_SUFX} \
		${WRKSRC}/obj/dist/bin/browser/features
# XXX Hack taken from lang/rust.
# XXX Taken from www/firefox.
# patch(1) in NetBSD does not handle .cargo-checksum.json like long width file.
# Replace checksum fields for following patches:
# patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1
# patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_other_mod.rs,v 1.1
# patch-rust-1.39.0
	${CP} ${WRKSRC}/mozilla-release/third_party/rust/libc/.cargo-checksum.json \
	      ${WRKSRC}/mozilla-release/third_party/rust/libc/.cargo-checksum.json.orig
	${SED}	-e 's/4d9f7091af8e166943ac6f42ce85558909e5b6e61325039bff7adfbcf4b90212/7f3da734d5e2e9426051da4f406e46d9e9bed43ed2d7d048e8afc8af7ed44795/' \
		-e 's/1cd66ed5967c788562d4ad626cfbeb1544f4b9267111de5f6790379b8327f28e/6ae549dd21581748b2f1d82880eaca3445c11e3354965e5b49b20342075a3e52/' \
		-e 's/a3540eab4dbc52e006e84e288bad17e1dae3865fea49020e0ed8b5a7724a9532/5e58a2109f5eff0f497dfac150c161c1d517a2227b49e086da96c3d66522ac3a/' \
		< ${WRKSRC}/mozilla-release/third_party/rust/libc/.cargo-checksum.json.orig \
		> ${WRKSRC}/mozilla-release/third_party/rust/libc/.cargo-checksum.json
	${CP} ${WRKSRC}/mozilla-release/third_party/rust/bindgen/.cargo-checksum.json \
	      ${WRKSRC}/mozilla-release/third_party/rust/bindgen/.cargo-checksum.json.orig
	${SED}	-e 's/5788372d27bdbaaf0454bc17be31a5480918bc41a8a1c4832e8c61185c07f9cd/8c92a52c0f859c7bec7bfbc36b9d18f904baab0c8c9dc1b3e7af34de1a0b0da4/' \
		-e 's/b73865b6689d4f3546edd91909a47c329c4ae630ea97715d29bc683ae1dc17ad/efdada601d13c489451da9d65a78c42598841cebddf6f3a8012add2380628a51/' \
		-e 's/34f9aa76b6c9c05136bb69dcd6455397faef571a567254d2c541d50a962994db/e5581852eec87918901a129284b4965aefc8a19394187a8095779a084f28fabe/' \
		< ${WRKSRC}/mozilla-release/third_party/rust/bindgen/.cargo-checksum.json.orig \
		> ${WRKSRC}/mozilla-release/third_party/rust/bindgen/.cargo-checksum.json

post-patch:
	${SED}  -e 's/@MOZ_APP_DISPLAYNAME@/Cliqz Internet/g' \
		-e 's/@MOZ_APP_NAME@/cliqz/g' \
		-e '/Icon=cliqz/ s/cliqz/${CLIQZ_ICON}/' \
		-e '/StartupWMClass/d' \
		< ${MOZ_DESKTOP} \
		> ${CLIQZ_DESKTOP}
	for MOZ_CONFIGURE_ARG in ${MOZ_CONFIGURE_ARGS}; do \
		${ECHO} $$MOZ_CONFIGURE_ARG >> \
			${WRKSRC}/mozilla-release/browser/config/cliqz.mozconfig; \
	done;

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh

INSTALLATION_DIRS+=	share/applications share/pixmaps bin lib/cliqz
do-install:
	cd ${WRKSRC}/obj/dist/cliqz && \
		${PAX} -wr * ${DESTDIR}${PREFIX}/lib/cliqz && \
		${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${DESTDIR}${PREFIX}/lib/*
	cd ${DESTDIR}${PREFIX}/lib && \
		${FIND} . \(	-name \*.js  -or \
				-name \*.html -or \
				-name \*.xml -or \
				-name \*.svg \
			\) \
			-type f \
			-exec ${CHMOD} 0644 '{}' \;

post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/cliqz
	${ECHO} 'exec ${PREFIX}/lib/cliqz/cliqz "$$@"' >> ${DESTDIR}${PREFIX}/bin/cliqz
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/cliqz
	${INSTALL_DATA} ${CLIQZ_DESKTOP} ${DESTDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${CLIQZ_ICON_SRC} ${DESTDIR}${PREFIX}/share/pixmaps/${CLIQZ_ICON}

.include "../../lang/python/pyversion.mk"
.include "../../mk/compiler.mk"
# Force the use of clang from pkgsrc, regardless of the setting of
# PKGSRC_COMPILER.
# \todo This breaks the use of ccache, which should be fixed, probably
# by adding support for this kind of forcing to pkgsrc infrastructure.
PKG_CC=		${PREFIX}/bin/clang
PKG_CXX=	${PREFIX}/bin/clang++
BUILDLINK_DEPMETHOD.clang=     build
.include "../../lang/clang/buildlink3.mk"
RUST_REQ=	1.41.0
.include "../../lang/rust/rust.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
