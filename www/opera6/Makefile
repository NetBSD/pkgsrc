# $NetBSD: Makefile,v 1.1.1.1 2002/02/22 22:22:21 tron Exp $

DISTNAME=	opera-${OPERA_PKG_VERSION}
CATEGORIES=	www
MASTER_SITES=	ftp://opera.panix.com/pub/linux/${OPERA_DIR}/ \
		ftp://ftp.hu-berlin.de/pub/www/opera/linux/${OPERA_DIR}/ \
		http://ftp.opera.com/pub/opera/linux/${OPERA_DIR}/
EXTRACT_SUFX=	.rpm
DISTFILES=	opera-${OPERA_DIST_VERSION}.${OPERA_ARCH}${EXTRACT_SUFX}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	opera-license

# we need the DIST_SUBDIR=. because of the inclusion of suse's Makefile.common
DIST_SUBDIR=	.
EXTRACT_ONLY=	# empty
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == i386)
DEPENDS+=	suse_compat>=6.4:../../emulators/suse_compat
DEPENDS+=	suse_libjpeg>=6.4:../../emulators/suse_libjpeg
DEPENDS+=	suse_libpng>=6.4:../../emulators/suse_libpng
DEPENDS+=	suse_x11>=6.4:../../emulators/suse_x11

OPERA_ARCH=		i386
OPERA_DIR=		600/tp3
OPERA_DIST_VERSION=	6.0-20020110.1-static_qt
OPERA_PKG_VERSION=	5.99.3
.endif

RPMFILES=	${DISTFILES}

do-build:
	${SED} -e 's#@EMULDIR@#${EMULDIR}#g' ${FILESDIR}/opera.sh > \
	  ${WRKDIR}/opera

post-install: post-install-manpage
	${INSTALL_SCRIPT} ${WRKDIR}/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.common"

post-install-manpage:
# The SuSE common makefile defines "MANCOMPRESSED".
.if defined(MANCOMPRESSED)
	${GZIP_CMD} ${EMULDIR}/usr/share/man/man1/opera.1
	${LN} -fs ../${EMULSUBDIR}/usr/share/man/man1/opera.1.gz \
	  ${PREFIX}/man/man1
.else
	${LN} -fs ../${EMULSUBDIR}/usr/share/man/man1/opera \
	  ${PREFIX}/man/man1
.endif
