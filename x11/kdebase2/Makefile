# $NetBSD: Makefile,v 1.49 2004/10/03 00:18:36 tv Exp $

DISTNAME=	kdebase-2.2.2
PKGREVISION=	7
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 2 integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-ssl-dir="${SSLBASE}" \
			--with-ldap=${BUILDLINK_PREFIX.openldap} \
			--disable-greet-lib \
			--without-pam --without-cdparanoia \
			--without-lame --without-vorbis

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic
.endif

PLIST_SRC=		${WRKDIR}/PLIST.Xdpms
UNLIMIT_RESOURCES=      datasize

.if ${OPSYS} == "Linux"
KDE2_NSPLUGINS?=	YES
.else
KDE2_NSPLUGINS?=	NO
.endif
BUILD_DEFS+=		KDE2_NSPLUGINS

.if ${KDE2_NSPLUGINS} == "YES"
PLIST_SRC+=		${PKGDIR}/PLIST.nsplugins
CONFIGURE_ARGS+=	--with-motif-includes="${MOTIFBASE}/include" \
			--with-motif-libraries="${MOTIFBASE}/lib"
.include "../../mk/motif.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif

# Don't execute kappfinder_install at install-time.  This causes random
# applications to be found which causes random .desktop files to be created
# in the applnk directory.
#
CONFIGURE_ENV+=		RUN_KAPPFINDER=no

PLIST_SRC+=		${PKGDIR}/PLIST

ICONDIR=		share/kde/icons

post-configure:
	ln -s ../Linux/conf.c ${WRKSRC}/ksysguard/ksysguardd/FreeBSD/conf.c
	ln -s ../Linux/conf.h ${WRKSRC}/ksysguard/ksysguardd/FreeBSD/conf.h
	ln -s ../Linux/ksysguardd.h ${WRKSRC}/ksysguard/ksysguardd/FreeBSD/ksysguardd.h
	ln -s ../Linux/conf.c ${WRKSRC}/ksysguard/ksysguardd/Solaris/conf.c
	ln -s ../Linux/conf.h ${WRKSRC}/ksysguard/ksysguardd/Solaris/conf.h
	ln -s ../Linux/ksysguardd.h ${WRKSRC}/ksysguard/ksysguardd/Solaris/ksysguardd.h

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
	@# KDE2 finds executables, the files must have their read bit set
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

.include "../../databases/openldap/buildlink3.mk"
.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdelibs2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
