# $NetBSD: Makefile,v 1.17.2.1 2003/03/02 10:24:17 agc Exp $

DISTNAME=	kdebase-3.0.5a
PKGREVISION=	3
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 3 integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_PREFIX.openssl}"
CONFIGURE_ARGS+=	--with-ldap="${BUILDLINK_PREFIX.openldap}"
CONFIGURE_ARGS+=	--without-pam
CONFIGURE_ARGS+=	--without-cdparanoia
CONFIGURE_ARGS+=	--without-lame
CONFIGURE_ARGS+=	--without-vorbis

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			${EXPORT_SYMBOLS_LDFLAGS}
.if exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.endif
.endif

PLIST_SRC=		${WRKDIR}/PLIST.Xdpms

.if ${OPSYS} == "Linux"
KDE3_NSPLUGINS?=	YES
.else
KDE3_NSPLUGINS?=	NO
.endif
BUILD_DEFS+=		KDE3_NSPLUGINS

.if ${KDE3_NSPLUGINS} == "YES"
PLIST_SRC+=		${PKGDIR}/PLIST.nsplugins
CONFIGURE_ARGS+=	--with-motif-includes="${BUILDLINK_PREFIX.motif}/include"
CONFIGURE_ARGS+=	--with-motif-libraries="${BUILDLINK_PREFIX.motif}/lib"
.include "../../mk/motif.buildlink2.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif

_KDE3_EXTRA_INCLUDES=	${LOCALBASE}/include:${X11BASE}/include:${BUILDLINK_PREFIX.freetype2}/include/freetype2

# Don't execute kappfinder_install at install-time.  This causes random
# applications to be found which causes random .desktop files to be created
# in the applnk directory.
#
CONFIGURE_ENV+=		RUN_KAPPFINDER=no

PLIST_SRC+=		${PKGDIR}/PLIST

ICONDIR=		share/kde/icons

FOO_MAIN_FILES= \
	kate/app/dummy_main.cpp \
	kcontrol/access/kaccess_main.cpp \
	kcontrol/kcontrol/kcminit_main.cpp \
	kcontrol/kcontrol/kcmshell_main.cpp \
	kcontrol/kcontrol/kcontrol_main.cpp \
	kdeprint/kjobviewer/kjobviewer_main.cpp \
	kdesktop/kdesktop_main.cc \
	khotkeys/khotkeys/khotkeys_main.cpp \
	kicker/kicker_main.cpp \
	kicker/proxy/appletproxy_main.cpp \
	kicker/proxy/extensionproxy_main.cpp \
	klipper/klipper_main.cpp \
	kmenuedit/kmenuedit_main.cpp \
	konqueror/client/kfmclient_main.cc \
	konqueror/keditbookmarks/keditbookmarks_main.cpp \
	konqueror/konqueror_main.cc \
	konsole/konsole/konsole_main.cpp \
	konsole/konsole/kwrited_main.cpp \
	ksmserver/ksmserver_main.cpp \
	kxkb/kxkb_main.cpp \
	legacyimport/klegacyimport_main.cpp

.include "../../x11/kde3/Makefile.foo_main"

# Several programs need to be setuid-root, but due to the way that KDE3
# finds executables, the files must have their read bit set so that
# KStandardDir::findResource() will find them.
#
_KDE_SETUID_ROOT=	${ROOT_USER} ${ROOT_GROUP} 4755
SPECIAL_PERMS+=	${PREFIX}/bin/konsole_grantpty	${_KDE_SETUID_ROOT}
SPECIAL_PERMS+=	${PREFIX}/bin/kcheckpass	${_KDE_SETUID_ROOT}
SPECIAL_PERMS+=	${PREFIX}/bin/ksysguardd	${_KDE_SETUID_ROOT}

post-build:
	cd ${WRKSRC};							\
	files="kioslave/info/kde-info2html.conf";			\
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

.include "../../databases/openldap/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
