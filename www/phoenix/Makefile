# $NetBSD: Makefile,v 1.1.1.1 2002/10/15 11:23:56 grant Exp $
#

DISTNAME=		phoenix-0.3-i686-pc-linux-gnu
PKGNAME=		phoenix-0.3
CATEGORIES=		www
MASTER_SITES=		http://ftp.mozilla.org/pub/phoenix/releases/0.3/

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.mozilla.org/projects/phoenix/
COMMENT=		Lightweight web browser based on Mozilla source

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

WRKSRC=			${WRKDIR}/phoenix
NO_CONFIGURE=		# defined

MESSAGE_SRC=		${PKGDIR}/MESSAGE.${OPSYS}

do-build:

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/phoenix.sh >	\
		${WRKDIR}/phoenix.sh

do-install:
	cd ${WRKDIR} && ${PAX} -rw phoenix ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKDIR}/phoenix.sh ${PREFIX}/bin/phoenix

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.else
.  include "../../mk/bsd.pkg.mk"
.endif

