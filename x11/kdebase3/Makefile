# $NetBSD: Makefile,v 1.3 2002/07/17 07:54:06 skrll Exp $

DISTNAME=	kdebase-3.0.2
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 3 integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_DIR}"
CONFIGURE_ARGS+=	--without-pam
CONFIGURE_ARGS+=	--without-cdparanoia
CONFIGURE_ARGS+=	--without-lame
CONFIGURE_ARGS+=	--without-vorbis

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic
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
CONFIGURE_ARGS+=	--with-motif-includes="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-motif-libraries="${BUILDLINK_DIR}/lib"
.include "../../mk/motif.buildlink.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif

_KDE3_EXTRA_INCLUDES=	${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include:${BUILDLINK_DIR}/include/freetype2

# Don't execute kappfinder_install at install-time.  This causes random
# applications to be found which causes random .desktop files to be created
# in the applnk directory.
#
CONFIGURE_ENV+=		RUN_KAPPFINDER=no

PLIST_SRC+=		${PKGDIR}/PLIST

ICONDIR=		share/kde/icons

post-build:
	cd ${WRKSRC};							\
	files="kioslave/info/kde-info2html.conf";			\
	for file in $${files}; do					\
		${SED}	-e "s|@LOCALBASE@|${LOCALBASE}|"		\
			$${file} > $${file}.new;			\
		${MV} -f $${file}.new $${file};				\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/templates/.source/emptydir
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/${ICONDIR}
	${INSTALL_DATA} ${DISTDIR}/Daemon.README			\
		${PREFIX}/share/doc/kde/HTML/en/kdm

	@# Several programs need to be setuid-root, but due to the way that
	@# KDE3 finds executables, the files must have their read bit set
	@# so that KStandardDir::findResource() will find them
	@#
	suid_progs="							\
		bin/konsole_grantpty					\
		bin/kcheckpass						\
		bin/ksysguardd						\
	";								\
	for prog in $${suid_progs}; do					\
		${CHMOD} 4755 ${PREFIX}/$${prog};			\
	done

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

.include "../../databases/openldap/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../x11/qt3-tools/buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdelibs3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
