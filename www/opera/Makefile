# $NetBSD: Makefile,v 1.64.2.1 2007/04/23 19:16:57 ghen Exp $

DISTNAME=		opera-${OPERA_PKG_VERSION:S/u/pl/}
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.hu-berlin.de/pub/www/opera/${OPERA_DIR}/
MASTER_SITES+=		http://ftp.sunet.se/pub/www/clients/Opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.task.gda.pl/pub/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://opera.nsc.no/pub/nsc.no/mirrors/operasoftware/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.opera.com/pub/opera/${OPERA_DIR}/
DISTFILES=		opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}${EXTRACT_SUFX}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.opera.com/
COMMENT=		Small, fast and customizable WWW client

ONLY_FOR_PLATFORM=	NetBSD-*-i386 SunOS-*-sparc FreeBSD-*-i386 DragonFly-*-i386

LICENSE=		opera-850-license

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=		YES
USE_LANGUAGES=		# empty

.include "../../mk/bsd.prefs.mk"

OPERA_LANG=		en
OPERA_VER_DATE=		20070409
OPERA_PKG_VERSION=	9.20
OPERA_PKG_VERSION_DIR=	920

_OPERA_OPSYS?=		${OPSYS}
_OPERA_MACHINE_ARCH?=	${MACHINE_ARCH}

.if (${_OPERA_OPSYS} == NetBSD) || (${_OPERA_OPSYS} == DragonFly)
DEPENDS+=		suse_x11>=7.3:../../emulators/${SUSE_DIR_PREFIX}_x11

# we need the DIST_SUBDIR=. because of the inclusion of suse's Makefile.common
DIST_SUBDIR=		.
EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

EXTRACT_SUFX=		.rpm
OPERA_ARCH=		.i386
OPERA_DIR=		linux/${OPERA_PKG_VERSION_DIR}/final/${OPERA_LANG}/${OPERA_ARCH:S/.//}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/beta.*//:C/u.*//}-${OPERA_VER_DATE}.1-static-qt

RPMFILES=		${DISTFILES}
RPM2PKGSTRIP=		1

.elif (${_OPERA_OPSYS} == FreeBSD)
OPERA_ARCH=		.i386.freebsd
OPERA_DIR=		unix/freebsd/${OPERA_PKG_VERSION_DIR}/final/${OPERA_LANG}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/u.*//}-${OPERA_VER_DATE}.1-static-qt

WRKSRC=			${WRKDIR}/opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}

OWN_DIRS=		${PREFIX}/share/opera/plugins

.elif (${_OPERA_OPSYS} == SunOS) && (${_OPERA_MACHINE_ARCH} == sparc)
EXTRACT_SUFX=		.tar.bz2
OPERA_ARCH=		-sol8-sparc
OPERA_DIR=		unix/solaris/${OPERA_PKG_VERSION_DIR}/final/${OPERA_LANG}/${_OPERA_MACHINE_ARCH}/static
OPERA_DIST_VERSION=	${OPERA_PKG_VERSION:C/u.*//}-${OPERA_VER_DATE}.1-static-qt

WRKSRC=			${WRKDIR}/opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}-521

BUILD_DEFS+=		INSTALL_ETC_OPERARC
INSTALL_ETC_OPERARC?=	no
OWN_DIRS=		${PREFIX}/lib/opera/plugins

.  if !empty(INSTALL_ETC_OPERARC:M[yY][eE][sS])
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc \
			/etc/opera6rc
CONF_FILES+=		${PREFIX}/share/opera/config/opera6rc.fixed \
			/etc/opera6rc.fixed
.  endif

PLIST_SUBST+=		OPERA_VER_DATE=${OPERA_VER_DATE:Q}
PLIST_SUBST+=		OPERA_PKG_VERSION=${OPERA_PKG_VERSION:C/u.*//}

.endif

.if (((${_OPERA_OPSYS} == SunOS) && (${_OPERA_MACHINE_ARCH} == sparc)) || (${_OPERA_OPSYS} == FreeBSD))
NO_BUILD=		YES

SUBST_CLASSES+=		opera
SUBST_STAGE.opera=	post-build
SUBST_FILES.opera=	man/opera.1
SUBST_SED.opera=	-e 's,/usr/,${PREFIX}/,g'

.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
.if (${_OPERA_OPSYS} == NetBSD) || (${_OPERA_OPSYS} == DragonFly)
	@ ${SED} -e 's#@EMULDIR@#${EMULDIR}#g' ${FILESDIR}/opera.sh > \
		${WRKDIR}/opera

post-install: post-install-manpage
	${INSTALL_SCRIPT} ${WRKDIR}/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(MANCOMPRESSED)
USE_TOOLS+=		gzip
.endif

.PHONY: post-install-manpage
post-install-manpage:
# The SuSE common makefile defines "MANCOMPRESSED=yes".
.  if defined(MANCOMPRESSED) && !empty(MANCOMPRESSED:M[yY][eE][sS])
	${LN} -fs ../../${EMULSUBDIR}/usr/share/man/man1/opera.1.gz \
		${PREFIX}/${PKGMANDIR}/man1
.  else
	${GUNZIP_CMD} -c ${EMULDIR}/usr/share/man/man1/opera.1.gz >
		${PREFIX}/${PKGMANDIR}/man1/opera.1
.  endif
.endif

.if (((${_OPERA_OPSYS} == SunOS) && (${_OPERA_MACHINE_ARCH} == sparc)) || (${_OPERA_OPSYS} == FreeBSD))
do-install:
	@${ECHO} "n" > ${WRKSRC}/inst.cmd
	@${ECHO} "n" >> ${WRKSRC}/inst.cmd
	@cd ${WRKSRC} && ${CAT} ${WRKSRC}/inst.cmd | ./install.sh --prefix=${PREFIX:Q}
	@${ECHO} "=> You can ignore any previous lines about opera6rc"
	@${ECHO}

post-install:
	@${INSTALL_MAN} ${WRKSRC}/man/opera.1 ${PREFIX}/${PKGMANDIR}/man1
.endif

# regenerate distinfo for all ports supported by this package
.PHONY: opera-distinfo
opera-distinfo:
	( ${ECHO} '$$'NetBSD'$$'; \
	  ${ECHO} ''; \
	_OPERA_OPSYS=NetBSD ${MAKE} distinfo 1>&2; \
		${GREP} opera distinfo; \
	_OPERA_OPSYS=FreeBSD ${MAKE} distinfo 1>&2; \
		${GREP} opera distinfo; \
	_OPERA_OPSYS=SunOS _OPERA_MACHINE_ARCH=sparc make distinfo 1>&2; \
		${GREP} opera distinfo; \
	) > distinfo.new
	${MV} -f distinfo.new distinfo

.include "../../mk/bsd.pkg.mk"
