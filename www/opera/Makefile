# $NetBSD: Makefile,v 1.19 2001/04/30 10:23:24 abs Exp $

DISTNAME=	opera-5.0b8
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/linux/tgz/ \
		ftp://ftp.opera.com/pub/opera/linux/  \
		ftp://gd.tuwien.ac.at/infosys/browsers/opera/linux/tgz/tgz/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/tgz/
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
DEPENDS+=	linuxppc_lib>=2000.q4.2:../../emulators/linuxppc_lib

OPERA_ARCH=	ppc
.endif

RPMFILES=	opera-static-5.0b8-20010426.023.1.${OPERA_ARCH}.rpm

post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/bin/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.common"
