# $NetBSD: Makefile,v 1.2 2002/12/03 08:59:48 grant Exp $
#

DISTNAME=		mozilla-i686-pc-linux-gnu-1.2.1
PKGNAME=		mozilla-linux-1.2.1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_MOZILLA:=mozilla1.2.1/}

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.mozilla.org/
COMMENT=		Open-source version of the Netscape browser (binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

WRKSRC=			${WRKDIR}/mozilla
NO_CONFIGURE=		# defined

MESSAGE_SRC=		${PKGDIR}/MESSAGE.${OPSYS}

do-build:

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/mozilla.sh >	\
		${WRKDIR}/mozilla.sh

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mozilla-linux
	cd ${WRKSRC}; && ${PAX} -rw . ${PREFIX}/lib/mozilla-linux
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla.sh ${PREFIX}/bin/mozilla-linux

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.else
.  include "../../mk/bsd.pkg.mk"
.endif

