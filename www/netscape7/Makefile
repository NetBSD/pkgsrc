# $NetBSD: Makefile,v 1.22 2003/09/19 13:21:11 wiz Exp $
#

DISTNAME=		netscape-i686-pc-linux-gnu-sea
PKGNAME=		netscape${VERS_MAJ}-${VERS_MAJ}.${VERS_MIN}
PKGREVISION=		2
WRKSRC=			${WRKDIR}/netscape-installer
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.netscape.com/pub/netscape7/${SUB}/ \
			ftp://sunsite.utk.edu/pub/netscape/netscape7/${SUB}/ \
			ftp://ftp.netscape.org/pub/netscape7/${SUB}/ \
			ftp://ftp-uk.netscape.com/pub/netscape7/${SUB}/ \
			ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.netscape.com/pub/netscape7/${SUB}/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://channels.netscape.com/ns/browsers/default.jsp
COMMENT=		Netscape Browser, Mail and Newsreader suite, version 7

RESTRICTED=		"No re-distribution without agreement from Netscape"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386
INTERACTIVE_STAGE=	build

PKG_LANG?=		english
VERS_MAJ=		7
VERS_MIN=		1
SUB=			${PKG_LANG}/${VERS_MAJ}.${VERS_MIN}/unix/${DIST_DIR_NAME}/sea
DIST_SUBDIR=		netscape/${VERS_MAJ}.${VERS_MIN}/${PKG_LANG}

.if ${PKG_LANG} != english
DISTINFO_FILE=		${.CURDIR}/distinfo.${PKG_LANG}
.endif

PLIST_SRC=		${WRKDIR}/PLIST

pre-fetch:
	@${CAT} ${FILESDIR}/fetch-message

pre-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/netscape.sh > 	\
		${WRKDIR}/netscape7
	@delay=10;							\
	${SED} -e "s|@WRKSRC@|${WRKSRC}|g" -e "s|@delay@|$${delay}|g"	\
		${FILESDIR}/extract_instructions;			\
	sleep $${delay};						\
	${MKDIR} ${WRKSRC}/dest
	${SED} -e "s|/usr/local/netscape|${WRKSRC}/dest|g" 		\
		${WRKSRC}/config.ini > ${WRKSRC}/config.ini.new;	\
       ${MV} ${WRKSRC}/config.ini.new ${WRKSRC}/config.ini

# we must wait for netscape to start up after build!
do-build:
	cd ${WRKSRC} && ${SH} netscape-installer
	@sleep 10

# dynamic PLIST generation
pre-install:
	if [ -f ${INSTDIR}/plugins/libjavaplugin_oji.so ]; then	\
		cd ${INSTDIR}/plugins && ${LN} -sf 			\
			java2/plugin/i386/ns600/libjavaplugin_oji.so	\
			libjavaplugin_oji.so;				\
	fi
	@${RM} -f ${PLIST_SRC}
	@${TOUCH} ${PLIST_SRC}
	@${ECHO} 'bin/netscape7' >> ${PLIST_SRC}
	@cd ${INSTDIR} && 						\
		${FIND} . ! -name "xpti.dat" \( -type f -or -type l \)  \
			-print |					\
		${SED} -e 's,^\.,lib/netscape/netscape7,' >> ${PLIST_SRC}
	@${ECHO} "@unexec \$${RM} %D/lib/netscape/netscape7/components/xpti.dat 2>/dev/null || \$${TRUE}" \
		>> ${PLIST_SRC}
	@cd ${INSTDIR} && 						\
			${FIND} ${FIND_ARG} \( -type d ! -name "." \)	\
			-print |					\
		${SED} -e 's,^\.,@dirrm lib/netscape/netscape7,' >>	\
			${PLIST_SRC}
	@${ECHO} "@dirrm lib/netscape/netscape7" >> ${PLIST_SRC}
	@${ECHO} "@unexec \$${RMDIR} %D/lib/netscape 2>/dev/null || \$${TRUE}" \
		>> ${PLIST_SRC}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/netscape/netscape7
	cd ${INSTDIR} && ${PAX} -rw . ${PREFIX}/lib/netscape/netscape7
	${INSTALL_SCRIPT} ${WRKDIR}/netscape7 ${PREFIX}/bin
	${CHMOD} 755 ${PREFIX}/bin/netscape7

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.include "../../mk/bsd.pkg.mk"
