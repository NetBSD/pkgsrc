# $NetBSD: Makefile,v 1.20 2004/07/01 19:05:56 recht Exp $

DISTNAME=	opera-${OPERA_PKG_VERSION}
PKGREVISION=	# empty
CATEGORIES=	www
MASTER_SITES=	http://www.panix.com/opera/files/${OPERA_DIR}/ \
		ftp://ftp.hu-berlin.de/pub/www/opera/${OPERA_DIR}/ \
		http://ftp.sunet.se/pub/www/clients/Opera/${OPERA_DIR}/ \
		http://opera.online.no/${OPERA_DIR}/ \
		ftp://ftp.task.gda.pl/pub/opera/${OPERA_DIR}/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/${OPERA_DIR}/ \
		ftp://ftp.opera.com/pub/opera/${OPERA_DIR}/
DISTFILES=	opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}${EXTRACT_SUFX}

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

ONLY_FOR_PLATFORM=	NetBSD-*-i386 SunOS-*-sparc FreeBSD-*-i386

LICENSE=	opera-license

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=           YES
NO_CONFGURE=            YES
NO_TOOLS=               YES
USE_LANGUAGES=          # empty

.include "../../mk/bsd.prefs.mk"

# A default so lintpkgsrc is happy
OPERA_PKG_VERSION=	7.51

.if (${OPSYS} == NetBSD)
DEPENDS+=	suse_compat>=7.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_freetype2>=7.3:../../emulators/${SUSE_DIR_PREFIX}_freetype2
DEPENDS+=	suse_libjpeg>=7.3:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
DEPENDS+=	suse_libpng>=7.3:../../emulators/${SUSE_DIR_PREFIX}_libpng
DEPENDS+=	suse_x11>=7.3:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=	suse_openmotif>=7.3:../../emulators/${SUSE_DIR_PREFIX}_openmotif

# we need the DIST_SUBDIR=. because of the inclusion of suse's Makefile.common
DIST_SUBDIR=	.
EXTRACT_ONLY=	# empty
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

EXTRACT_SUFX=		.rpm
OPERA_ARCH=		.i386
OPERA_LANG=		en
OPERA_VER_DATE=		20040602
OPERA_PKG_VERSION=	7.51
OPERA_DIR=		linux/${OPERA_PKG_VERSION:S/.//g:C/beta.*//}/final/${OPERA_LANG}/${OPERA_ARCH:S/.//}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/beta.*//}-${OPERA_VER_DATE}.1-static-qt

RPMFILES=	${DISTFILES}

.elif (${OPSYS} == FreeBSD)
EXTRACT_SUFX=		.tar.bz2
OPERA_ARCH=		.i386.freebsd
OPERA_LANG=		en
OPERA_VER_DATE=		20040602
OPERA_PKG_VERSION=	7.51
OPERA_DIR=		unix/freebsd/${OPERA_PKG_VERSION:S/.//g:}/final/${OPERA_LANG}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION}-${OPERA_VER_DATE}.1-static-qt

WRKSRC=			${WRKDIR}/opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}

OWN_DIRS=		${PREFIX}/share/opera/plugins

.elif (${OPSYS} == SunOS) && (${MACHINE_ARCH} == sparc)
EXTRACT_SUFX=		.tar.bz2
OPERA_ARCH=		-sol8-sparc-local
OPERA_LANG=		en
OPERA_VER_DATE=		20040602
OPERA_PKG_VERSION=	7.51
OPERA_DIR=		unix/solaris/${OPERA_PKG_VERSION:S/.//g}/final/${OPERA_LANG}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION}-${OPERA_VER_DATE}.1-static-qt

WRKSRC=			${WRKDIR}/opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}

BUILD_DEFS+=		INSTALL_ETC_OPERARC
INSTALL_ETC_OPERARC?=	no
OWN_DIRS=		${PREFIX}/lib/opera/plugins

.  if !empty(INSTALL_ETC_OPERARC:M[yY][eE][sS])
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc \
			/etc/opera6rc
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc.fixed \
			/etc/opera6rc.fixed
.  endif

PLIST_SUBST+=		OPERA_VER_DATE=${OPERA_VER_DATE}
PLIST_SUBST+=		OPERA_PKG_VERSION=${OPERA_PKG_VERSION}

.endif

.if (((${OPSYS} == SunOS) && (${MACHINE_ARCH} == sparc)) || (${OPSYS} == FreeBSD))
NO_BUILD=               YES
USE_PKGINSTALL=		YES

SUBST_CLASSES+=		opera7
SUBST_STAGE.opera7=	pre-install
SUBST_FILES.opera7=	${WRKSRC}/man/opera.1
SUBST_SED.opera7=	-e 's,/usr/,${PREFIX}/,g'

.endif

do-build:
.if (${OPSYS} == NetBSD)
	@ ${SED} -e 's#@EMULDIR@#${EMULDIR}#g' ${FILESDIR}/opera.sh > \
		${WRKDIR}/opera

post-install: post-install-manpage
	${INSTALL_SCRIPT} ${WRKDIR}/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"

post-install-manpage:
  # The SuSE common makefile defines "MANCOMPRESSED".
.  if defined(MANCOMPRESSED)
	${GZIP_CMD} ${EMULDIR}/usr/share/man/man1/opera.1
	${LN} -fs ../../${EMULSUBDIR}/usr/share/man/man1/opera.1.gz \
		${PREFIX}/man/man1
.  else
	${LN} -fs ../../${EMULSUBDIR}/usr/share/man/man1/opera \
		${PREFIX}/man/man1
.  endif
.endif

.if (((${OPSYS} == SunOS) && (${MACHINE_ARCH} == sparc)) || (${OPSYS} == FreeBSD))
do-install:
	@cd ${WRKSRC} && ${ECHO} "n" | ./install.sh --prefix=${PREFIX}
	@${ECHO} "=> You can ignore any previous lines about opera6rc"
	@${ECHO}

post-install:
	@${INSTALL_MAN} ${WRKSRC}/man/opera.1 ${PREFIX}/man/man1
.endif

.include "../../mk/bsd.pkg.mk"
