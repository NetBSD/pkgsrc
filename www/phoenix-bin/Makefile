# $NetBSD: Makefile,v 1.1 2003/04/14 19:56:28 grant Exp $
#

DISTNAME=		phoenix-0.5-i686-pc-linux-gnu
PKGNAME=		phoenix-bin-0.5
WRKSRC=			${WRKDIR}/phoenix
CATEGORIES=		www
MASTER_SITES=		http://ftp.mozilla.org/pub/phoenix/releases/0.5/

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.mozilla.org/projects/phoenix/
COMMENT=		Lightweight gecko-based web browser (binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

CONFLICTS+=		phoenix-linux-[0-9]*

NO_CONFIGURE=		# defined

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PHOENIX_LIB=		${PREFIX}/lib/phoenix-linux

do-build:

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/phoenix.sh >	\
		${WRKDIR}/phoenix.sh

do-install:
	${INSTALL_DATA_DIR} ${PHOENIX_LIB}
	cd ${WRKSRC} && ${CP} -r . ${PHOENIX_LIB}
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
