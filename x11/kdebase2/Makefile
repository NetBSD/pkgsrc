# $NetBSD: Makefile,v 1.28 2001/11/13 21:10:45 jlam Exp $

DISTNAME=	kdebase-2.2.1
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 2 integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_DIR}"
CONFIGURE_ARGS+=	--disable-greet-lib
CONFIGURE_ARGS+=	--without-pam
CONFIGURE_ARGS+=	--without-cdparanoia
CONFIGURE_ARGS+=	--without-lame
CONFIGURE_ARGS+=	--without-vorbis
CONFIGURE_ARGS+=	--without-ldap

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic
.endif

PLIST_SRC=		${WRKDIR}/PLIST.Xdpms

.if ${OPSYS} == "Linux"
KDE2_NSPLUGINS?=	YES
.else
KDE2_NSPLUGINS?=	NO
.endif
BUILD_DEFS+=		KDE2_NSPLUGINS

.if ${KDE2_NSPLUGINS} == "YES"
PLIST_SRC+=		${PKGDIR}/PLIST.nsplugins
CONFIGURE_ARGS+=	--with-motif-includes="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-motif-libraries="${BUILDLINK_DIR}/lib"
.include "../../mk/motif.buildlink.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif

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

	@# Several programs need to be setuid-root, so we need to remove
	@# remove read/write permissions for security reasons.
	@#
	suid_progs="							\
		bin/konsole_grantpty					\
		bin/kcheckpass						\
		bin/ksysguardd						\
	";								\
	for prog in $${suid_progs}; do					\
		${CHMOD} 4711 ${PREFIX}/$${prog};			\
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
		lib/kde2/libkcm_energy.so				\
		lib/kde2/libkcm_screensaver.so				\
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

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdelibs2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
