# $NetBSD: Makefile,v 1.58 2004/10/03 00:18:36 tv Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 3 integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README
SITES_Daemon.png=	${MASTER_SITE_LOCAL}	
SITES_Daemon.README=	${MASTER_SITE_LOCAL}	

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
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
			kicker/kicker-3.1-properSizeSetting.pl \
			kioslave/finger/kio_finger.pl \
			kioslave/info/kde-info2html \
			klipper/klipper-1-2.pl \
			kwin/data/kwin3_plugin.pl \
			kwin/data/pluginlibFix.pl \
			konsole/schemaStrip.pl

CONF_FILES=		${PREFIX}/share/kde/config/kdm/kdmrc \
			${PKG_SYSCONFDIR}/kdm/kdmrc
OWN_DIRS=		${PKG_SYSCONFDIR}/kdm
RCD_SCRIPTS=		kdm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			${EXPORT_SYMBOLS_LDFLAGS}
.endif

PLIST_SRC=		${WRKDIR}/PLIST.Xdpms

_KDE3_EXTRA_INCLUDES=	${LOCALBASE}/include:${X11BASE}/include:${BUILDLINK_PREFIX.freetype2}/include/freetype2

# Don't execute kappfinder_install at install-time.  This causes random
# applications to be found which causes random .desktop files to be created
# in the applnk directory.
#
CONFIGURE_ENV+=		RUN_KAPPFINDER=no

PLIST_SRC+=		${PKGDIR}/PLIST

.if exists(${X11BASE}/include/X11/extensions/Xrandr.h)
HAVE_RANDR!=		${GREP} XRRSetScreenConfigAndRateX  ${X11BASE}/include/X11/extensions/Xrandr.h; ${ECHO}
.endif
.if defined(HAVE_RANDR) && !empty(HAVE_RANDR)
PLIST_SUBST+=		HAVE_RANDR=""
.else
PLIST_SUBST+=		HAVE_RANDR="@comment "
.endif

.if exists(${X11BASE}/lib/libXcursor.so)
PLIST_SUBST+=		HAVE_XCURSOR=""
.else
PLIST_SUBST+=		HAVE_XCURSOR="@comment "
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
	${SED} -e 's|^#\(LogoPixmap\)=.*|\1=${PREFIX}/${ICONDIR}/Daemon.png|' \
		kdmrc > ${WRKDIR}/kdmrc.ad;				\
	${CP} -f ${WRKDIR}/kdmrc.ad kdmrc
.endif

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../databases/openldap/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
