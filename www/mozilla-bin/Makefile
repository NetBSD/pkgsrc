# $NetBSD: Makefile,v 1.1 2003/04/14 20:28:22 grant Exp $
#

DISTNAME=		mozilla-i686-pc-linux-gnu-1.3
PKGNAME=		mozilla-bin-1.3
WRKSRC=			${WRKDIR}/mozilla
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_MOZILLA:=mozilla1.3/}

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.mozilla.org/
COMMENT=		Open-source version of the Netscape browser (binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

CONFLICTS+=		mozilla-linux-[0-9]*

NO_CONFIGURE=		# defined

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

MOZILLA_LIB=		${PREFIX}/lib/mozilla-linux

do-build:

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/mozilla.sh >	\
		${WRKDIR}/mozilla.sh

do-install:
	${INSTALL_DATA_DIR} ${MOZILLA_LIB}
	cd ${WRKSRC} && ${CP} -r . ${MOZILLA_LIB}
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla.sh ${PREFIX}/bin/mozilla-linux

post-install:
	@${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	@${FIND} ${MOZILLA_LIB} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	@${FIND} ${MOZILLA_LIB} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.include "../../mk/bsd.pkg.mk"
