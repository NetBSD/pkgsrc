# $NetBSD: Makefile,v 1.13 2003/11/21 10:35:14 jlam Exp $

DISTNAME=	opera-${OPERA_PKG_VERSION}
PKGREVISION=	# empty
CATEGORIES=	www
MASTER_SITES=	http://www.panix.com/opera/files/${OPERA_DIR}/ \
		ftp://ftp.hu-berlin.de/pub/www/opera/${OPERA_DIR}/ \
		http://ftp.sunet.se/pub/www/clients/Opera/${OPERA_DIR}/ \
		http://opera.online.no/${OPERA_DIR}/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/${OPERA_DIR}/ \
		ftp://ftp.opera.com/pub/opera/${OPERA_DIR}/
DISTFILES=	opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}${EXTRACT_SUFX}

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

ONLY_FOR_PLATFORM=	NetBSD-*-i386 SunOS-*-sparc

LICENSE=	opera-license

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

# we need the DIST_SUBDIR=. because of the inclusion of suse's Makefile.common
DIST_SUBDIR=	.
EXTRACT_ONLY=	# empty
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

EXTRACT_SUFX=		.rpm
OPERA_ARCH=		.i386
OPERA_LANG=		en
OPERA_PKG_VERSION=	7.22
OPERA_DIR=		linux/${OPERA_PKG_VERSION:S/.//g:C/beta.*//}/final/${OPERA_LANG}/${OPERA_ARCH:S/.//}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/beta.*//}-20031103.1-static-qt

RPMFILES=	${DISTFILES}

.elif (${OPSYS} == SunOS) && (${MACHINE_ARCH} == sparc)
EXTRACT_SUFX=		.tar.bz2
OPERA_ARCH=		-sol8-sparc-local
OPERA_LANG=		en
OPERA_VER_DATE=		20031103
OPERA_PKG_VERSION=	7.22
OPERA_DIR=		unix/solaris/${OPERA_PKG_VERSION:S/.//g}/final/${OPERA_LANG}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION}-${OPERA_VER_DATE}.1-static-qt

WRKSRC=			${WRKDIR}/opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}

SOLARIS_INSTALL_ETC_OPERARC?=	no
BUILD_DEFS+=		SOLARIS_INSTALL_ETC_OPERARC
OWN_DIRS=		${PREFIX}/lib/opera/plugins

.  if !empty(SOLARIS_INSTALL_ETC_OPERARC:M[yY][eE][sS])
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc \
			/etc/opera6rc
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc.fixed \
			/etc/opera6rc.fixed
.  endif

PLIST_SUBST+=		OPERA_VER_DATE=${OPERA_VER_DATE}

SUBST_CLASSES+=		opera7
SUBST_STAGE.opera7=	post-build
SUBST_FILES.opera7=	${WRKSRC}/man/opera.1
SUBST_SED.opera7=	-e 's,/usr/,${PREFIX}/,g'
.endif

do-build:
.if (${MACHINE_ARCH} == i386)
	${SED} -e 's#@EMULDIR@#${EMULDIR}#g' ${FILESDIR}/opera.sh > \
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

.if (${OPSYS} == SunOS) && (${MACHINE_ARCH} == sparc)
USE_PKGINSTALL=		YES

do-install:
	@cd ${WRKSRC} && ${ECHO} "n" | ./install.sh --prefix=${PREFIX}
	@${ECHO} "=> You can ignore the previous lines about '... cannot be prefixed'"
	@${ECHO}

post-install:
	@${INSTALL_MAN} ${WRKSRC}/man/opera.1 ${PREFIX}/man/man1
.endif

.include "../../mk/bsd.pkg.mk"
