# $NetBSD: Makefile,v 1.23 2002/04/04 11:56:46 tron Exp $

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
DEPENDS+=	suse_compat>=6.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_libjpeg>=6.4:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
DEPENDS+=	suse_libpng>=6.4:../../emulators/${SUSE_DIR_PREFIX}_libpng
DEPENDS+=	suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11

OPERA_ARCH=	${MACHINE_ARCH}
.elif (${MACHINE_ARCH} == powerpc)
DEPENDS+=	linuxppc_lib>=2000.4.2:../../emulators/linuxppc_lib

OPERA_ARCH=	ppc
.endif

RPMFILES=	opera-static-5.0-1.${OPERA_ARCH}.rpm

post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/bin/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"
