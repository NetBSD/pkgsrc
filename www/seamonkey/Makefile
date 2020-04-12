# $NetBSD: Makefile,v 1.207 2020/04/12 08:29:18 adam Exp $

DISTNAME=	seamonkey-${SM_VER}.source
PKGNAME=	seamonkey-${SM_VER:S/b/beta/}
PKGREVISION=	6
SM_VER=		2.49.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=seamonkey/releases/${SM_VER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.seamonkey-project.org/
COMMENT=	Full-featured gecko-based browser
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/.source//}
MOZILLA_DIR=	mozilla/
PLIST_SRC+=	${PLIST_SRC_DFLT}
USE_LANGUAGES+=	c c++
USE_TOOLS+=	unzip pax

NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/seamonkey
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/seamonkey-bin

.include "../../mk/bsd.prefs.mk"
.include "options.mk"
.include "../../www/firefox52/mozilla-common.mk"

# Workaround to fix pixman.h detection
CFLAGS+=	-I${BUILDLINK_PREFIX.pixman}/include/pixman-1

CONFIG_GUESS_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=suite

ALL_ENV+=		MOZILLA_PKG_NAME=${PKGBASE}

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

#.if (${OPSYS} == "Linux" || ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || \
#     ${OPSYS} == "DragonFly") && \
#    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
#BUILD_DEPENDS+=		yasm>=1.1.0:../../devel/yasm
#.endif

CHECK_PORTABILITY_SKIP+=	mozilla/js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=	mozilla/security/nss/tests/libpkix/libpkix.sh

CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpt.py

SUBST_CLASSES+=		sys-dic
SUBST_STAGE.sys-dic=	pre-configure
SUBST_MESSAGE.sys-dic=	Reference to system hunspell dictionaries.
SUBST_FILES.sys-dic=	mozilla/extensions/spellcheck/hunspell/src/mozHunspell.cpp
SUBST_VARS.sys-dic=	PREFIX

CHECK_WRKREF_SKIP=	lib/seamonkey/chrome/toolkit/content/global/buildconfig.html

post-extract:
	mv ${WRKSRC}/mozilla/gfx/ycbcr/yuv_row_arm.s ${WRKSRC}/mozilla/gfx/ycbcr/yuv_row_arm.S
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/mozilla/media/libcubeb/src

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf
# If there is no .mozconfig, codegen.pp target fails.
#	touch ${WRKSRC}/.mozconfig

post-install:
#	${TOUCH} ${TOUCH_FLAGS} \
#		${DESTDIR}${PREFIX}/include/seamonkey/mozilla/throw_gcc.h
	@${STEP_MSG} "Installing bundled seamonkey extensions."
	rm -rf ${WRKDIR}/${OBJDIR}/extensions
	${MKDIR} ${WRKDIR}/${OBJDIR}/extensions
	${RUN} for e in ${XPI_FILES}; do				\
	  subdir=`${UNZIP_CMD} -c "$$e" install.rdf | awk '/^    <em:id>/ {sub(".*<em:id>","");sub("</em:id>.*","");print;exit;}'` &&	\
	  ${MKDIR} "${WRKDIR}/${OBJDIR}/extensions/$$subdir" &&			\
	  cd "${WRKDIR}/${OBJDIR}/extensions/$$subdir" &&				\
	  ${UNZIP_CMD} -aqo $$e;					\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/seamonkey/extensions
	cd ${WRKDIR}/${OBJDIR}/extensions && pax -rw .				\
	   ${DESTDIR}${PREFIX}/lib/seamonkey/extensions/.
	rm -rf ${WRKDIR}/${OBJDIR}/extensions

.include "../../mk/bsd.pkg.mk"
