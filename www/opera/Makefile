# $NetBSD: Makefile,v 1.13 2001/03/22 23:46:47 tron Exp $

DISTNAME=	opera-5.0b7
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/linux/tgz/ \
		ftp://ftp.opera.com/pub/opera/linux/  \
		ftp://ftp.fh-koblenz.de/pub/InternetClients/Opera/english/4.0b4/linux/intel-x86/static/ \
		ftp://gd.tuwien.ac.at/infosys/browsers/opera/linux/tgz/tgz/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/tgz/
DISTFILES=	${RPMFILES}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

DEPENDS+=	suse_compat>=6.4:../../emulators/suse_compat
DEPENDS+=	suse_libjpeg>=6.4:../../emulators/suse_libjpeg
DEPENDS+=	suse_libpng>=6.4:../../emulators/suse_libpng
DEPENDS+=	suse_x11>=6.4:../../emulators/suse_x11

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	opera-license

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

RPMFILES=	opera-static-5.0b7-20010320.018.1.i386.rpm

post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/bin/opera ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.common"

DIST_SUBDIR=	.
