# $NetBSD: Makefile,v 1.216 2020/06/16 09:09:02 nia Exp $

DISTNAME=	seamonkey-${SM_VER}.source
PKGNAME=	seamonkey-${SM_VER:S/b/beta/}
PKGREVISION=	3
SM_VER=		2.53.2
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

GCC_REQD+=	6

.include "../../mk/bsd.prefs.mk"
.include "options.mk"
# See mozilla/config/milestone.txt
#.include "../../www/firefox60/mozilla-common.mk"
.include "mozilla-common.mk"

# Workaround to fix pixman.h detection
CFLAGS+=	-I${BUILDLINK_PREFIX.pixman}/include/pixman-1

CONFIG_GUESS_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=suite

ALL_ENV+=		MOZILLA_PKG_NAME=${PKGBASE}

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

CHECK_PORTABILITY_SKIP+=	mozilla/js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=	mozilla/modules/pdfium/update.sh
CHECK_PORTABILITY_SKIP+=	mozilla/security/nss/tests/libpkix/libpkix.sh

CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/seamonkey-sdk/sdk/bin/xpt.py

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/seamonkey/extensions
	cd ${WRKDIR}/${OBJDIR}/extensions && pax -rw .				\
	   ${DESTDIR}${PREFIX}/lib/seamonkey/extensions/.
	rm -rf ${WRKDIR}/${OBJDIR}/extensions

.include "../../mk/bsd.pkg.mk"
