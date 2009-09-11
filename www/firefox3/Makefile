# $NetBSD: Makefile,v 1.33.2.3 2009/09/11 13:38:53 tron Exp $

MOZILLA=		firefox3	# allow coexisting with firefox2
COMMENT=		Web browser with support for extensions

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

INSTALLATION_DIRS=	lib/pkgconfig share/applications share/pixmaps

CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.6.4

# Pull in standard firefox build framework, and override some things below.
# This include must appear first, to ensure that USE_LANGUAGES is set
# correctly before mk/compiler.mk may be loaded.
.include "../../www/firefox/Makefile-firefox.common"

MAINTAINER=		tnn@NetBSD.org
MOZ_VER=		3.0.14

XPTCFILES:=		${XPTCFILES:C,^,../../firefox3/files/,}
DESCR_SRC=		${.CURDIR}/../../www/firefox/DESCR

DISTINFO_FILE=		${.CURDIR}/../../www/firefox3/distinfo
PATCHDIR=		${.CURDIR}/../../www/firefox3/patches

.PHONY: copy-pkgconfig
post-extract: copy-pkgconfig
copy-pkgconfig:
	cp ${.CURDIR}/../../www/firefox3/files/*.pc ${WRKSRC:Q}/build/unix

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Substituting prefix in pkg-config files.
SUBST_FILES.fix-pc+=	build/unix/*.pc
SUBST_SED.fix-pc=	-e 's,@PREFIX@,${PREFIX},g'

# Need this to be able to reuse existing firefox pkgsrc infrastructure
.PHONY: create-dummy-c-sdk
pre-configure: create-dummy-c-sdk
create-dummy-c-sdk:
	mkdir -p ${WRKSRC:Q}/directory/c-sdk
	touch ${WRKSRC:Q}/directory/c-sdk/configure.in

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

# Link browser.xpt
.PHONY: stage-package
post-build: stage-package
stage-package:
	cd ${WRKSRC}/browser/installer && \
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} stage-package
	cp ${WRKSRC}/dist/firefox/components/browser.xpt \
	   ${WRKSRC}/dist/bin/components/browser.xpt

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
PLIST_SUBST+=		JEMALLOC=
SCRIPTS_ENV+=		JEMALLOC=
.PHONY: install-libjemalloc
post-install: install-libjemalloc
install-libjemalloc:
	${INSTALL_LIB} ${WRKSRC}/dist/lib/libjemalloc.${SO_SUFFIX} \
	  ${DESTDIR}${PREFIX}/lib/${MOZILLA}/libjemalloc.${SO_SUFFIX}
.else
PLIST_SUBST+=		JEMALLOC="@comment "
SCRIPTS_ENV+=		JEMALLOC="@comment "
.endif

.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox 3
MOZILLA_ICON=	${WRKSRC}/other-licenses/branding/firefox/default48.png
.else
MOZILLA_NAME=	Minefield 3
MOZILLA_ICON=	${WRKSRC}/browser/branding/unofficial/default48.png
.endif

.PHONY: install-desktop
post-install: install-desktop
install-desktop:
	${SED}							\
		-e 's|@MOZILLA@|${MOZILLA}|g'			\
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'		\
		-e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'		\
		<${.CURDIR}/../../www/firefox3/files/${MOZILLA}.desktop.in \
		>${WRKDIR}/${MOZILLA}.desktop
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop		\
	    ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}				\
	    ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

INSTALLATION_DIRS+=	lib/${MOZILLA}/modules

# configure says: "Can't use system PNG because it doesn't have APNG support"
CONFIGURE_ARGS+=	--without-system-png
# Override www/firefox's idea of toolkit
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
# Is dbus support useful for anything?
CONFIGURE_ARGS+=	--disable-dbus
# Avoids needing curl on Linux
CONFIGURE_ARGS+=	--disable-crashreporter

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

CONFIGURE_ARGS+=	--enable-system-sqlite
BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.5.9
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
