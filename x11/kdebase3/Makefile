# $NetBSD: Makefile,v 1.83 2005/06/16 01:11:04 markd Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 3 integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README
DISTFILES+=	NetBSD-flag.png
SITES_Daemon.png=	${MASTER_SITE_LOCAL}
SITES_Daemon.README=	${MASTER_SITE_LOCAL}
SITES_NetBSD-flag.png=	http://www.NetBSD.org/images/

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_DIRS+=		xdg-1.2
USE_PKGINSTALL=		YES

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"
CONFIGURE_ARGS+=	--with-ldap="${BUILDLINK_PREFIX.openldap}"
CONFIGURE_ARGS+=	--without-pam
CONFIGURE_ARGS+=	--without-cdparanoia
CONFIGURE_ARGS+=	--without-lame
CONFIGURE_ARGS+=	--without-vorbis
CONFIGURE_ARGS+=	--without-java

REPLACE_PERL= \
			kcontrol/fileshare/fileshareset \
			kcontrol/keys/convertShortcuts.pl \
			khelpcenter/searchhandlers/khc_htdig.pl \
			khelpcenter/searchhandlers/khc_htsearch.pl \
			khelpcenter/searchhandlers/khc_docbookdig.pl \
			khelpcenter/searchhandlers/khc_mansearch.pl \
			kicker/kicker-3.1-properSizeSetting.pl \
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

_KDE3_EXTRA_INCLUDES=	${LOCALBASE}/include:${X11BASE}/include:${BUILDLINK_PREFIX.freetype2}/include/freetype2

# Don't execute kappfinder_install at install-time.  This causes random
# applications to be found which causes random .desktop files to be created
# in the applnk directory.
#
CONFIGURE_ENV+=		RUN_KAPPFINDER=no

PLIST_SRC+=		${PKGDIR}/PLIST

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdebase
PKG_SUPPORTED_OPTIONS=	sasl samba
PKG_SUGGESTED_OPTIONS=	sasl

.include "../../mk/bsd.options.mk"

BUILDLINK_DEPENDS.Xrandr+=      Xrandr>=1.0

.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
LIBS+=			-L${BUILDLINK_PREFIX.samba}/lib/samba -Wl,-R${BUILDLINK_PREFIX.samba}/lib/samba
PLIST_SUBST+=		HAVE_SMB=""
.else
PLIST_SUBST+=		HAVE_SMB="@comment "
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
PLIST_SUBST+=		HAVE_USBVIEW=""
.else
PLIST_SUBST+=		HAVE_USBVIEW="@comment "
.endif

ICONDIR=		share/kde/icons

.if ${OPSYS} == "NetBSD"
SPECIAL_PERMS+=	${PREFIX}/bin/ksysguardd	${ROOT_USER} kmem 2755
.endif

pre-configure:
	cd ${WRKSRC};							\
	files="kcontrol/kdm/main.cpp kioslave/info/kde-info2html.conf";	\
	for file in $${files}; do					\
		${SED} ${FILES_SUBST_SED} $${file} > $${file}.new;	\
		${MV} -f $${file}.new $${file};				\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/templates/.source/emptydir
	${INSTALL_DATA} ${DISTDIR}/NetBSD-flag.png ${PREFIX}/${ICONDIR}
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/${ICONDIR}
	${INSTALL_DATA} ${DISTDIR}/Daemon.README			\
		${PREFIX}/share/doc/kde/HTML/en/kdm

	@# The global desktop template files need to be user-writeable, or
	@# else users won't be able to alter them after copying them to
	@# their local directories.
	@#
	${CHMOD} u+w ${PREFIX}/share/kde/templates/.source/*

	@# On some systems, the Xdpms routines aren't available in a shared
	@# library, and some libraries aren't created as a result.
	@#
	( files="							\
		lib/kde3/libkcm_energy.so				\
		lib/kde3/libkcm_screensaver.so				\
	  ";								\
	  for file in $${files}; do					\
		if [ -f ${PREFIX}/$${file} ]; then			\
			${ECHO} "$${file}";				\
		fi;							\
	  done;								\
	) > ${WRKDIR}/PLIST.Xdpms

.if ${OPSYS} == "NetBSD"
	@# NetBSD Advertisement O:-)
	cd ${PREFIX}/share/kde/config/kdm;				\
	${SED} -e 's|^\(LogoPixmap\)=.*|\1=${PREFIX}/${ICONDIR}/NetBSD-flag.png|' \
		kdmrc > ${WRKDIR}/kdmrc.ad;				\
	${CP} -f ${WRKDIR}/kdmrc.ad kdmrc
.endif

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-6]*)
CONFIGURE_ENV+= ac_cv_func_getutxent='no'
CONFIGURE_ENV+= kde_cv_path_fontconfig_config='NONE'
.endif

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../databases/openldap/buildlink3.mk"
.if ${OPSYS} != "SunOS"
.include "../../devel/libusb/buildlink3.mk"
.endif
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
