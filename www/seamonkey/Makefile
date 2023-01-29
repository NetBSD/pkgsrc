# $NetBSD: Makefile,v 1.254 2023/01/29 21:18:06 ryoon Exp $

DISTNAME=	seamonkey-${SM_VER}.source
PKGNAME=	seamonkey-${SM_VER:S/b/beta/}
PKGREVISION=	6
SM_VER=		2.53.13
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.seamonkey-project.org/
COMMENT=	All-in-one Internet application suite
LICENSE=	mpl-2.0

BUILD_DEPENDS+=	nasm>=2.13:../../devel/nasm

WRKSRC=		${WRKDIR}/${DISTNAME:S/.source//}
MOZILLA_DIR=
PLIST_SRC+=	${PLIST_SRC_DFLT}
USE_LANGUAGES+=	c c++
USE_TOOLS+=	unzip pax

NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/seamonkey
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/seamonkey-bin

GCC_REQD+=	6

.include "../../mk/bsd.prefs.mk"
.include "options.mk"
# See config/milestone.txt
#.include "../../www/firefox60/mozilla-common.mk"
.include "mozilla-common.mk"

# Workaround to fix pixman.h detection
CFLAGS+=	-I${BUILDLINK_PREFIX.pixman}/include/pixman-1

CONFIG_GUESS_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=comm/suite
CONFIGURE_ARGS+=	--enable-calendar
CONFIGURE_ARGS+=	--enable-irc
CONFIGURE_ARGS+=	--enable-dominspector

ALL_ENV+=		MOZILLA_PKG_NAME=${PKGBASE}
#ALL_ENV+=		MOZ_APP_NAME=${PKGBASE}

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}

CHECK_PORTABILITY_SKIP+=	js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=	modules/pdfium/update.sh
CHECK_PORTABILITY_SKIP+=	security/nss/tests/libpkix/libpkix.sh

CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=		lib/seamonkey/omni.ja

CKSUM_CRATES+=	third_party/rust/libc
# patch-mozilla_third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_other_mod.rs
CKSUMS+=	4d9f7091af8e166943ac6f42ce85558909e5b6e61325039bff7adfbcf4b90212
CKSUMS+=	30c5211b393d9314f880f63e29833785c8b55369102eec21170a0fe0fd1c4a16

# patch-fac963c3bc00
CKSUM_CRATES+=	third_party/rust/packed_simd
# src/api.rs
CKSUMS+=	f6e92f056565e6fd93f98829a408aee9e790251e0cbd8a8bc30c8662b4d6fabb
CKSUMS+=	bb1795e9657a8298d37d2349b45443f08e9e455399ad4b727018600728478c10
# src/codegen.rs
CKSUMS+=	a29d38fa0a85eaf787fb49989e625bf64effd5f39c126fbb2a24be206d2a3917
CKSUMS+=	db4f232fb9f5728db310b87dc8c4733be48afacab1053798c06106bef9a42b05
# src/codegen/bit_manip.rs
CKSUMS+=	17ecebcff1f080e712fea5eb51602a73f4201ed56a198220342c8eb55bb92692
CKSUMS+=	6de2918225f6e2f67f9cb18c07f986d1580759e4fd0448cd0124b9d025a6721f
# src/codegen/llvm.rs
CKSUMS+=	5bc6751293f9f184cf23d5df448c7d58b58b799e41c7a91f8ca41a5ba56e64ec
CKSUMS+=	b4ccbc0bad90038f00fc3c158736462d01d0053df3afa00f9169e67d1a264444
# src/codegen/math.rs
CKSUMS+=	35f96e37a78fcf0cdb02146b7f27a45108fe06a37fc2a54d8851ce131a326178
CKSUMS+=	dfcf02ad34e2fdfe22c3f1cc2822001cc895e65031b4d06e585e5047839febb7
# src/codegen/math/float.rs
CKSUMS+=	dd86c0449e576c83b719700962ac017c332987fac08d91f2b7a2b1b883598170
CKSUMS+=	2c1cbce155bc527ce34d472c0fef6bc3dadb79cd7a357dd7aa5b1ebeb1d77a13
# src/codegen/math/float/abs.rs
CKSUMS+=	f56e2b4b8055ea861c1f5cbc6b6e1d8e7e5af163b62c13574ddee4e09513bfbc
CKSUMS+=	d5aaadcf540bdb9b4264dca6471a255fd7bf509e763bef0239c0144a68466fea
# src/codegen/math/float/cos.rs
CKSUMS+=	ef3b511a24d23045b310315e80348a9b7fedb576fc2de52d74290616a0abeb2a
CKSUMS+=	17f28d2900c852dca221fa9c92a9cd5fe7fd2df8d427bbc60216c749b2be013d
# src/codegen/math/float/cos_pi.rs
CKSUMS+=	4e7631a5d73dac21531e09ef1802d1180f8997509c2c8fa9f67f322194263a97
CKSUMS+=	dbaf9f443f9846a491d4ec52210a7b5835dd593b03366e3135b05c37d70f9d6c
# src/codegen/math/float/exp.rs
CKSUMS+=	61b691598c41b5622f24e4320c1bdd08701e612a516438bdddcc728fc3405c8c
CKSUMS+=	d300058a4bcc7ae7976f216f81902cd73a9e603ad63880dff3bbc866c27a9f37
# src/codegen/math/float/ln.rs
CKSUMS+=	46b718b1ba8c9d99e1ad40f53d20dfde08a3063ca7bd2a9fdd6698e060da687e
CKSUMS+=	c851e211e43f8256093ba75b03ae0c307c9962ee66d94f09b4dd80068190cbdf
# src/codegen/math/float/mul_add.rs
CKSUMS+=	a37bf764345d4b1714f97e83897b7cf0855fc2811704bcbc0012db91825339e1
CKSUMS+=	041a5b69d5991d93ef795351b17560c10faf80b78fd26ad7df42a239b32cf9de
# src/codegen/math/float/mul_adde.rs
CKSUMS+=	c75702bfcb361de45964a93caf959a695ef2376bd069227600b8c6872665c755
CKSUMS+=	8eb4e1d2c10e890032d0ff976091ea89da16ea7c8234d608890c759e45d91e27
# src/codegen/math/float/powf.rs
CKSUMS+=	642346e982bc4c39203de0864d2149c4179cd7b21cf67a2951687932b4675872
CKSUMS+=	9742c3877f1a5509ca5c9492a40884b6579ba6dd11c26b7112e63f70666b395d
# src/codegen/math/float/sin.rs
CKSUMS+=	9d68164c90cdca6a85155040cdac42e27342ebe0b925273ef1593df721af4258
CKSUMS+=	0e9868d35531566509f3a01d85d5253045eb4afa8525d8407dcc1f5f33c56036
# src/codegen/math/float/sin_cos_pi.rs
CKSUMS+=	9be02ad48585a1e8d99129382fbffbaed47852f15459256a708850b6b7a75405
CKSUMS+=	0c8981df6970db6f33f0adad16b1979c1d1be24f9622a200736c162c8de41bf7
# src/codegen/math/float/sin_pi.rs
CKSUMS+=	9890347905b4d4a3c7341c3eb06406e46e60582bcf6960688bd727e5dadc6c57
CKSUMS+=	bb6d39db8f921e03a301fc5206ac1a61a97def8a2cb83b87ccf189f3fc48d548
# src/codegen/math/float/sqrt.rs
CKSUMS+=	e3c60dcfb0c6d2fc62adabcc931b2d4040b83cab294dea36443fb4b89eb79e34
CKSUMS+=	e6ebb0c5f428efad1f672b9a8fe4e58534dbf1ea5a8fe092ce5ce76b52fe89cb
# src/codegen/math/float/sqrte.rs
CKSUMS+=	f0f4ef9eb475ae41bcc7ec6a95ad744ba6b36925faa8b2c2814004396d196b63
CKSUMS+=	23acfaea38d0e081a6d9021c1094e813d0cfd12c58c1eca9662aade5e625d51c
# src/codegen/pointer_sized_int.rs
CKSUMS+=	a70697169c28218b56fd2e8d5353f2e00671d1150d0c8cef77d613bdfacd84cb
CKSUMS+=	6ca13c214b6cf7e0929dbe18e96a16fc0bb7d8799608df29c4c8115490f99e01
# src/codegen/reductions.rs
CKSUMS+=	645e2514746d01387ddd07f0aa4ffd8430cc9ab428d4fb13773ea319fa25dd95
CKSUMS+=	8eb18ebac76985d2aa30262a2edd8cb004230b511a765d657525f677a585c12c
# src/codegen/reductions/mask.rs
CKSUMS+=	8f1afe6aabf096a3278e1fc3a30f736e04aa8b9ce96373cee22162d18cfe2702
CKSUMS+=	f3bf63d36d5e4612eae7899693e2bc5fd2efabe6dc81e2c62afaef488105b460
# src/codegen/swap_bytes.rs
CKSUMS+=	1d6cdc716eadddc92b4fd506b2445a821caa8dc00860447de09d7ebd69c2087f
CKSUMS+=	0cd2c1ed297116e9d990259a99fcd633734105ce4bfb9fa7fda62e6aad3f3401
# src/codegen/vPtr.rs
CKSUMS+=	711c753a08d53a2879c4fb87a0762c46ce4e34c22f0ca88d2e4c557a0f679969
CKSUMS+=	f0753b405cdc865bdf8e82c6505f299ea1f96136239ebbaf7f9ce93d310764b8
# src/lib.rs
CKSUMS+=	41c2a5c5fb42225ce9c6a267653870fdb8af30f933b3b8534d57a15fb96ebb39
CKSUMS+=	11055443120e525054c65d0b520cc023aa31d6e941ae75cb6321eeb531a16655
# src/testing.rs
CKSUMS+=	1d3a7862ef625e235a5734ad7204e68d350f902c0695182b1f08a0552432416e
CKSUMS+=	896669c08d8c801448a4d2fadc9d633eda0fbe879d229997e2a182e31278e469

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

# error: Cannot set `RUSTC_BOOTSTRAP=1` from build script of `packed_simd v0.3.4 (https://github.com/hsivonen/packed_simd?rev=0917fe780032a6bbb23d71be545f9c1834128d75#0917fe78)`.
# note: Crates cannot set `RUSTC_BOOTSTRAP` themselves, as doing so would subvert the stability guarantees of Rust for your project.
# help: If you're sure you want to do this in your project, set the environment variable `RUSTC_BOOTSTRAP=packed_simd` before running cargo instead.
MAKE_ENV+=	RUSTC_BOOTSTRAP="packed_simd,encoding_rs"

post-extract:
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/${MOZILLA_DIR}/media/libcubeb/src

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf-2.13
##	cd ${WRKSRC}/${MOZILLA_DIR} && ${SETENV} ${CONFIGURE_ENV} autoconf-2.13
#	cd ${WRKSRC}/${MOZILLA_DIR}/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf-2.13
	${SED}	-e 's/@MOZ_APP_DISPLAYNAME@/SeaMonkey/g' \
		-e 's/@MOZ_APP_NAME@/seamonkey/g' \
		${WRKSRC}/${MOZILLA_DIR}/toolkit/mozapps/installer/linux/rpm/mozilla.desktop > \
		${WRKDIR}/seamonkey.desktop
## If there is no .mozconfig, codegen.pp target fails.
##	touch ${WRKSRC}/.mozconfig

# XXX: For PREFIX
#.include "../../mk/bsd.pkg.use.mk"
#do-configure:
#	echo mk_add_options MOZ_OBJDIR="${OBJDIR}" > ${WRKSRC}/comm/.mozconfig
#.for i in ${CONFIGURE_ARGS}
#	echo ac_add_options $i >> ${WRKSRC}/comm/.mozconfig
#.endfor

#do-build:
#	env ${MAKE_ENV} ${WRKSRC}/mach build

post-install:
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

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
