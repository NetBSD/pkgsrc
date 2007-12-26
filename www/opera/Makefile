# $NetBSD: Makefile,v 1.79 2007/12/26 20:32:59 jdolecek Exp $

DISTNAME=		opera-${OPERA_PKG_VERSION:S/u/pl/}
#PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://ftp.sunet.se/pub/www/clients/Opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.hu-berlin.de/pub/www/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.task.gda.pl/pub/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/${OPERA_DIR}/
MASTER_SITES+=		ftp://opera.nsc.no/pub/nsc.no/mirrors/operasoftware/${OPERA_DIR}/
MASTER_SITES+=		ftp://ftp.opera.com/pub/opera/${OPERA_DIR}/
DISTFILES=		opera-${OPERA_DIST_VERSION}${OPERA_ARCH}-${OPERA_LANG}${EXTRACT_SUFX}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.opera.com/
COMMENT=		Small, fast and customizable WWW client

LICENSE=		opera-850-license

EMUL_PLATFORMS=		freebsd-i386
EMUL_PLATFORMS+=	linux-i386
EMUL_PLATFORMS+=	solaris-sparc

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		# empty
BUILD_DIRS=		# empty

OPERA_LANG=		en
OPERA_VER_DATE=		20071214
OPERA_PKG_VERSION=	9.25
OPERA_PKG_VERSION_DIR=	925

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PLIST_SUBST+=		OPERA_VER_DATE=${OPERA_VER_DATE:Q}
PLIST_SUBST+=		OPERA_PKG_VERSION=${OPERA_PKG_VERSION:C/u.*//}

.if ${EMUL_PLATFORM} == "linux-i386"
.  include "Makefile.rpm"
.else
.  include "Makefile.plain"
.endif

.include "../../mk/bsd.pkg.mk"
