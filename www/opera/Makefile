# $NetBSD: Makefile,v 1.21 2001/05/15 12:01:16 tron Exp $

DISTNAME=	opera-5.0.1
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/linux/RPM/500/ \
		ftp://ftp.opera.com/pub/opera/linux/500/
DISTFILES=	${RPMFILES}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	opera-license

# we need the DIST_SUBDIR=. because of the inclusion of suse's Makefile.common
DIST_SUBDIR=	.
EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == i386)
DEPENDS+=	suse_compat>=6.4:../../emulators/suse_compat
DEPENDS+=	suse_libjpeg>=6.4:../../emulators/suse_libjpeg
DEPENDS+=	suse_libpng>=6.4:../../emulators/suse_libpng
DEPENDS+=	suse_x11>=6.4:../../emulators/suse_x11

OPERA_ARCH=	${MACHINE_ARCH}
.elif (${MACHINE_ARCH} == powerpc)
DEPENDS+=	linuxppc_lib>=2000.4.2:../../emulators/linuxppc_lib

OPERA_ARCH=	ppc
.endif

RPMFILES=	opera-static-5.0-1.${OPERA_ARCH}.rpm

post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/bin/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.common"
