# $NetBSD: Makefile,v 1.267 2024/01/30 14:22:38 ryoon Exp $

DISTNAME=	seamonkey-${SM_VER}.source
PKGNAME=	seamonkey-${SM_VER:S/b/beta/}
PKGREVISION=	11
SM_VER=		2.53.16
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/source/}
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

CKSUM_CRATES+= third_party/rust/libc/
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

post-extract:
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/${MOZILLA_DIR}/media/libcubeb/src

pre-configure:
	cd ${BUILDLINK_DIR}/bin && ${LN} -sf ${PYTHONBIN} python3
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
