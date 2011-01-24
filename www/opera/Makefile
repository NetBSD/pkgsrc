# $NetBSD: Makefile,v 1.90 2011/01/24 21:46:18 ahoka Exp $
#

DISTNAME=	opera-11.00-1176.i386
PKGNAME=	${DISTNAME:S/-1176.i386//}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/linux/1100/
EXTRACT_SUFX=	.rpm

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Opera web browser
LICENSE=	opera-eula

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64

EMUL_PLATFORMS+=        linux-i386

# TODO: add gstreamer
EMUL_MODULES.linux=     x11 fontconfig
EMUL_REQD=              suse>=10.0

EMUL_PKG_FMT=           rpm
RPM2PKG_PREFIX=         ${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=      ${EMULSUBDIR}
RPM2PKG_STAGE=          do-install

PKG_DESTDIR_SUPPORT=	user-destdir

#.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
USE_LANGUAGES=		# none

SUBST_CLASSES+=		opera-sh
SUBST_STAGE.opera-sh=	post-build
SUBST_FILES.opera-sh=	opera.sh
SUBST_VARS.opera-sh=	EMULDIR SH

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PLIST_SUBST+=		OPERA_VER_DATE=${OPERA_VER_DATE:Q}
PLIST_SUBST+=		OPERA_PKG_VERSION=${OPERA_PKG_VERSION:C/u.*//}

post-extract:
	${CP} ${FILESDIR}/opera.sh ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/opera.sh ${DESTDIR}${PREFIX}/bin/opera
	${LN} -fs ${EMULDIR}/usr/share/man/man1/opera.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${ECHO} "bin/opera" >> ${RPM2PKG_PLIST}
	${ECHO} "${PKGMANDIR}/man1/opera.1" >> ${RPM2PKG_PLIST}
	${ECHO} "${PREFIX}/lib/netscape/plugins=1" >> \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/share/opera/defaults/pluginpath.ini

.include "../../mk/bsd.pkg.mk"
