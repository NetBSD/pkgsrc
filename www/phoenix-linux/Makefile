# $NetBSD: Makefile,v 1.3 2002/10/31 00:47:02 grant Exp $
#

DISTNAME=		phoenix-0.4-i686-pc-linux-gnu
PKGNAME=		phoenix-linux-0.4
CATEGORIES=		www
MASTER_SITES=		http://ftp.mozilla.org/pub/phoenix/releases/0.4/

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.mozilla.org/projects/phoenix/
COMMENT=		A redesign of the Mozilla browser component (binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

WRKSRC=			${WRKDIR}/phoenix
NO_CONFIGURE=		# defined

MESSAGE_SRC=		${PKGDIR}/MESSAGE.${OPSYS}

do-build:

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/phoenix.sh >	\
		${WRKDIR}/phoenix.sh

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/phoenix-linux
	cd ${WRKDIR}/phoenix; && ${PAX} -rw .  ${PREFIX}/lib/phoenix-linux
	${INSTALL_SCRIPT} ${WRKDIR}/phoenix.sh ${PREFIX}/bin/phoenix-linux

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.else
.  include "../../mk/bsd.pkg.mk"
.endif

