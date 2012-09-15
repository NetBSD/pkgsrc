# $NetBSD: Makefile,v 1.170 2012/09/15 10:07:07 obache Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
PKGREVISION=	22
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 3 integrated X11 desktop

#PATCH_SITES=	ftp://ftp.kde.org/pub/kde/security_patches/ \
#		http://mirrors.isc.org/pub/kde/security_patches/
#PATCHFILES=	post-3.5.7-kdebase-konqueror-2.diff post-3.5.7-kdebase-kdm.diff

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README
DISTFILES+=	NetBSD-flag-1.0.png
SITES.Daemon.png=	${MASTER_SITE_LOCAL}
SITES.Daemon.README=	${MASTER_SITE_LOCAL}
SITES.NetBSD-flag-1.0.png=	${MASTER_SITE_LOCAL}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

UNLIMIT_RESOURCES=	datasize
USE_TOOLS+=		pkg-config mkfontdir bdftopcf

FONTS_DIRS.x11+=	${PREFIX}/share/kde/apps/konsole/fonts
REQD_DIRS+=		${PREFIX}/share/kde/apps/konsole
REQD_DIRS+=		${PREFIX}/share/kde/apps/konsole/fonts

FONTS_DIRS.x11+=	${PREFIX}/share/kde/fonts/override
REQD_DIRS+=		${PREFIX}/share/kde/fonts
REQD_DIRS+=		${PREFIX}/share/kde/fonts/override

CONFIGURE_ARGS+=	--with-ldap="${BUILDLINK_PREFIX.openldap-client}"
CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"
CONFIGURE_ARGS+=	--without-java

REPLACE_PERL+=		kcontrol/keys/convertShortcuts.pl \
			khelpcenter/searchhandlers/khc_docbookdig.pl.in \
			khelpcenter/searchhandlers/khc_htdig.pl.in \
			khelpcenter/searchhandlers/khc_htsearch.pl \
			khelpcenter/searchhandlers/khc_mansearch.pl \
			kicker/kicker/kicker-3.1-properSizeSetting.pl \
			kicker/kicker/kicker-3.5-kconfigXTize.pl \
			kicker/kicker/kicker-3.5-taskbarEnums.pl \
			kioslave/finger/kio_finger.pl \
			kioslave/info/kde-info2html \
			klipper/klipper-1-2.pl \
			kwin/data/kwin3_plugin.pl \
			kwin/data/pluginlibFix.pl \
			konsole/schemaStrip.pl

CONF_FILES=		${PREFIX}/share/kde/config/kdm/kdmrc \
			${PKG_SYSCONFDIR}/kdm/kdmrc
CONF_FILES+=		${PREFIX}/share/examples/kdebase3/ksysguarddrc \
			${PKG_SYSCONFDIR}/ksysguarddrc
CONF_FILES+=		${PREFIX}/share/examples/kdebase3/kde-information.menu \
			${PKG_SYSCONFDIR}/xdg/menus/kde-information.menu
CONF_FILES+=		${PREFIX}/share/examples/kdebase3/kde-screensavers.menu \
			${PKG_SYSCONFDIR}/xdg/menus/kde-screensavers.menu
CONF_FILES+=		${PREFIX}/share/examples/kdebase3/kde-settings.menu \
			${PKG_SYSCONFDIR}/xdg/menus/kde-settings.menu
CONF_FILES+=		${PREFIX}/share/examples/kdebase3/applications-merged/kde-essential.menu \
			${PKG_SYSCONFDIR}/xdg/menus/applications-merged/kde-essential.menu
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/menus/applications-merged
OWN_DIRS=		${PKG_SYSCONFDIR}/kdm
RCD_SCRIPTS=		kdm

.include "../../mk/bsd.prefs.mk"

LIBS.NetBSD+=		${EXPORT_SYMBOLS_LDFLAGS}

PLIST_SRC=		${WRKDIR}/PLIST.Xdpms

_KDE3_EXTRA_INCLUDES=	${PREFIX}/include:${X11BASE}/include:${BUILDLINK_PREFIX.freetype2}/include/freetype2

# Don't execute kappfinder_install at install-time.  This causes random
# applications to be found which causes random .desktop files to be created
# in the applnk directory.
#
CONFIGURE_ENV+=		RUN_KAPPFINDER=no

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

BUILDLINK_API_DEPENDS.Xrandr+=	Xrandr>=1.0
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=${_KDE_VERSION}

DEPENDS+=		htdig>=3.2.0:../../www/htdig

# Solaris 10 has libusb only for 32 bit ABI (see PR 33727).
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--without-libusb
.endif

PLIST_VARS+=		usbview
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
PLIST.usbview=		yes
.endif

PLIST_VARS+=		joystick
.if ${OPSYS} == "Linux"
PLIST.joystick=		yes
.endif

ICONDIR=		share/icons

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
SPECIAL_PERMS+=	${PREFIX}/bin/ksysguardd	${REAL_ROOT_USER} kmem 2555
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "SunOS"
SUBST_CLASSES+=		varlock
SUBST_STAGE.varlock=	post-patch
SUBST_MESSAGE.varlock=	Fix lock directory path.
SUBST_FILES.varlock=	kcheckpass/kcheckpass.c
.  if ${OPSYS} == "SunOS"
SUBST_SED.varlock=	-e s:/var/lock:/var/spool/locks:
.  else
SUBST_SED.varlock=	-e s:/var/lock:/var/spool/lock:
.  endif
.endif

SUBST_CLASSES+=		htdig
SUBST_STAGE.htdig=	post-patch
SUBST_MESSAGE.htdig=	Fix htdig paths.
SUBST_FILES.htdig=	khelpcenter/searchhandlers/khc_htsearch.pl
SUBST_SED.htdig=	-e s:/srv/www/cgi-bin:${PREFIX}/libexec/cgi-bin:

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	kcontrol/kdm/main.cpp kioslave/info/kde-info2html.conf
SUBST_SED.paths=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

SUBST_CLASSES+=		xkb
SUBST_FILES.xkb=	kxkb/x11helper.cpp
SUBST_SED.xkb=		-e 's:XLIBDIR:"${X11BASE}/lib/X11/", "${X11BASE}/share/X11/", XLIBDIR:'
SUBST_STAGE.xkb=	post-patch

# genkdmconf wont install faces if using destdir so do it ourselves
INSTALLATION_DIRS+= share/kde/apps/kdm/faces share/kde/templates/.source/emptydir

pre-configure:
	cd ${WRKSRC}/ksysguard/ksysguardd && rm -f DragonFly && ln -s FreeBSD DragonFly

post-install:
	${INSTALL_DATA} ${WRKSRC}/kdm/kfrontend/pics/default1.png \
		${DESTDIR}${PREFIX}/share/kde/apps/kdm/faces/.default.face.icon
	${INSTALL_DATA} ${WRKSRC}/kdm/kfrontend/pics/root1.png \
		${DESTDIR}${PREFIX}/share/kde/apps/kdm/faces/root.face.icon
	${INSTALL_DATA} ${DISTDIR}/NetBSD-flag-1.0.png ${DESTDIR}${PREFIX}/${ICONDIR}/NetBSD-flag.png
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${DESTDIR}${PREFIX}/${ICONDIR}
	${INSTALL_DATA} ${DISTDIR}/Daemon.README			\
		${DESTDIR}${PREFIX}/share/doc/kde/HTML/en/kdm

	@# The global desktop template files need to be user-writeable, or
	@# else users won't be able to alter them after copying them to
	@# their local directories.
	@#
	${CHMOD} u+w ${DESTDIR}${PREFIX}/share/kde/templates/.source/*

	@# On some systems, the Xdpms routines aren't available in a shared
	@# library, and some libraries aren't created as a result.
	@#
	( files="							\
		lib/kde3/libkcm_energy.so				\
		lib/kde3/libkcm_screensaver.so				\
	  ";								\
	  for file in $${files}; do					\
		if [ -f ${DESTDIR}${PREFIX}/$${file} ]; then		\
			${ECHO} "$${file}";				\
		fi;							\
	  done;								\
	) > ${WRKDIR}/PLIST.Xdpms

.if ${OPSYS} == "NetBSD"
	@# NetBSD Advertisement O:-)
	cd ${DESTDIR}${PREFIX}/share/kde/config/kdm;			\
	${SED} -e 's|^\(LogoPixmap\)=.*|\1=${PREFIX}/${ICONDIR}/NetBSD-flag.png|' \
		kdmrc > ${WRKDIR}/kdmrc.ad;				\
	${CP} -f ${WRKDIR}/kdmrc.ad kdmrc
.endif

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-6]*)
CONFIGURE_ENV+= ac_cv_func_getutxent='no'
.endif

.if ${OPSYS} == "NetBSD"
# We always use pkg-config for detecting the fontconfig version, since there
# may exist an old version of fontconfig-config on systems that have been
# updated from NetBSD 1.x.
CONFIGURE_ENV+= kde_cv_path_fontconfig_config='NONE'
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.if ${OPSYS} != "SunOS"
.include "../../devel/libusb/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
