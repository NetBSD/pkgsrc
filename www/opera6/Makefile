# $NetBSD: Makefile,v 1.11 2002/07/04 22:11:21 tron Exp $

DISTNAME=	opera-${OPERA_PKG_VERSION}
CATEGORIES=	www
MASTER_SITES=	ftp://opera.panix.com/pub/linux/${OPERA_DIR}/ \
		ftp://ftp.hu-berlin.de/pub/www/opera/linux/${OPERA_DIR}/ \
		http://ftp.sunet.se/pub/www/clients/Opera/linux/${OPERA_DIR}/ \
		http://ftp.opera.com/pub/opera/linux/${OPERA_DIR}/ \
		http://opera.online.no/linux/${OPERA_DIR}/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_DIR}/ \
		ftp://ftp.opera.com/pub/opera/linux/
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

# A default so lintpkgsrc is happy
OPERA_PKG_VERSION=             6.02

.if (${MACHINE_ARCH} == i386)
DEPENDS+=	suse_compat>=6.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_libjpeg>=6.4:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
DEPENDS+=	suse_libpng>=6.4:../../emulators/${SUSE_DIR_PREFIX}_libpng
DEPENDS+=	suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11

OPERA_ARCH=		i386
OPERA_DIR=		602/final/en/qt_static
OPERA_DIST_VERSION=	6.02-20020701.1-static-qt
OPERA_PKG_VERSION=	6.02
.endif

RPMFILES=	${DISTFILES}

do-build:
	${SED} -e 's#@EMULDIR@#${EMULDIR}#g' ${FILESDIR}/opera.sh > \
	  ${WRKDIR}/opera

post-install: post-install-manpage
	${INSTALL_SCRIPT} ${WRKDIR}/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"

post-install-manpage:
# The SuSE common makefile defines "MANCOMPRESSED".
.if defined(MANCOMPRESSED)
	${GZIP_CMD} ${EMULDIR}/usr/share/man/man1/opera.1
	${LN} -fs ../../${EMULSUBDIR}/usr/share/man/man1/opera.1.gz \
	  ${PREFIX}/man/man1
.else
	${LN} -fs ../../${EMULSUBDIR}/usr/share/man/man1/opera \
	  ${PREFIX}/man/man1
.endif
