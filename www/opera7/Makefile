# $NetBSD: Makefile,v 1.10 2003/11/14 19:45:54 jdolecek Exp $

DISTNAME=	opera-${OPERA_PKG_VERSION}
PKGREVISION=	# empty
CATEGORIES=	www
MASTER_SITES=	http://www.panix.com/opera/files/linux/${OPERA_DIR}/ \
		ftp://ftp.hu-berlin.de/pub/www/opera/linux/${OPERA_DIR}/ \
		http://ftp.sunet.se/pub/www/clients/Opera/linux/${OPERA_DIR}/ \
		http://ftp.opera.com/pub/opera/linux/${OPERA_DIR}/ \
		http://opera.online.no/linux/${OPERA_DIR}/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_DIR}/ \
		ftp://ftp.opera.com/pub/opera/linux/
EXTRACT_SUFX=	.rpm
DISTFILES=	opera-${OPERA_DIST_VERSION}.${OPERA_ARCH}-en${EXTRACT_SUFX}

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	opera-license

# we need the DIST_SUBDIR=. because of the inclusion of suse's Makefile.common
DIST_SUBDIR=	.
EXTRACT_ONLY=	# empty
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

USE_BUILDLINK2=	# defined

.include "../../mk/bsd.prefs.mk"

# A default so lintpkgsrc is happy
OPERA_PKG_VERSION=	7.0

.if (${MACHINE_ARCH} == i386)
DEPENDS+=	suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_freetype2>=7.3:../../emulators/${SUSE_DIR_PREFIX}_freetype2
DEPENDS+=	suse_libjpeg>=7.3:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
DEPENDS+=	suse_libpng>=7.3:../../emulators/${SUSE_DIR_PREFIX}_libpng
DEPENDS+=	suse_x11>=7.3:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=	suse_openmotif>=7.3:../../emulators/${SUSE_DIR_PREFIX}_openmotif

OPERA_ARCH=		i386
OPERA_PKG_VERSION=	7.22
OPERA_DIR=		${OPERA_PKG_VERSION:S/.//g:C/beta.*//}/final/en/i386/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/beta.*//}-20031103.1-static-qt
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

.include "../../mk/bsd.pkg.mk"
