# $NetBSD: Makefile,v 1.8 2002/10/02 01:09:06 jschauma Exp $
#

DISTNAME=		netscape-i686-pc-linux-gnu-sea
PKGNAME=		netscape${VERS_MAJ}-${VERS_MIN}
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.netscape.com/pub/netscape7/${SUB}/ \
			ftp://sunsite.utk.edu/pub/netscape/netscape7/${SUB}/ \
			ftp://ftp.netscape.org/pub/netscape7/${SUB}/ \
			ftp://ftp-uk.netscape.com/pub/netscape7/${SUB}/ \
			ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.netscape.com/pub/netscape7/${SUB}/

MAINTAINER=		jschauma@netbsd.org
HOMEPAGE=		http://channels.netscape.com/ns/browsers/default.jsp
COMMENT=		Netscape Browser/Mail- and Newsreader suite version 7

RESTRICTED=		"No re-distribution without agreement from Netscape"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386
INTERACTIVE_STAGE=	build

VERS_MAJ=		7
VERS_MIN=		0
SUB=			${PKG_LANG}/${VERS_MAJ}.${VERS_MIN}/unix/${DIST_DIR_NAME}/sea
DIST_SUBDIR=		netscape7/${PKG_LANG}
WRKSRC=			${WRKDIR}/netscape-installer

PKG_LANG?=		english
NS_INST?=		recommended

.if ${PKG_LANG} != english
DISTINFO_FILE=		${PKGDIR}/distinfo.${PKG_LANG}
.endif

.if ${NS_INST} == "complete"
PLIST_SRC+=		${PKGDIR}/PLIST.extra
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.${PKG_LANG} ${PKGDIR}/PLIST

pre-fetch:
	@${CAT} ${FILESDIR}/fetch-message

pre-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/netscape.sh > 	\
		${WRKDIR}/netscape7
	@delay=10;							\
	${SED} -e "s|@NS_INST@|${NS_INST}|g" -e "s|@WRKSRC@|${WRKSRC}|g"\
		 -e "s|@delay@|$${delay}|g"				\
		${FILESDIR}/extract_instructions;			\
	sleep $${delay};						\
	${MKDIR} ${WRKSRC}/dest

do-build:
	cd ${WRKSRC} && ${SH} netscape-installer

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/netscape/netscape7
	cd ${WRKSRC}/dest && ${PAX} -rw . ${PREFIX}/lib/netscape/netscape7
	${INSTALL_SCRIPT} ${WRKDIR}/netscape7 ${PREFIX}/bin
	${CHMOD} 755 ${PREFIX}/bin/netscape7

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.else
.  include "../../mk/bsd.pkg.mk"
.endif
