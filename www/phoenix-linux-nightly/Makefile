# $NetBSD: Makefile,v 1.1.1.1 2003/03/26 12:55:04 grant Exp $
#

DISTNAME=		phoenix-i686-pc-linux-gnu
PKGNAME=		phoenix-linux-${PKGVER}
CATEGORIES=		www
MASTER_SITES=		http://komodo.mozilla.org/pub/phoenix/nightly/latest-trunk/

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.mozilla.org/projects/phoenix/
COMMENT=		Lightweight gecko-based web browser (nightly binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

PKGVER!=		date +%Y%m%d
DIST_SUBDIR=		${PKGNAME}
WRKSRC=			${WRKDIR}/phoenix
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PHOENIX_LIB=		${PREFIX}/lib/phoenix-linux

do-build:

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/phoenix.sh >	\
		${WRKDIR}/phoenix.sh

do-install:
	${INSTALL_DATA_DIR} ${PHOENIX_LIB}
	cd ${WRKSRC}; && ${CP} -r . ${PHOENIX_LIB}
	${INSTALL_SCRIPT} ${WRKDIR}/phoenix.sh ${PREFIX}/bin/phoenix-linux

post-install:
	@${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	@${FIND} ${PHOENIX_LIB} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	@${FIND} ${PHOENIX_LIB} -type d -print				\
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
