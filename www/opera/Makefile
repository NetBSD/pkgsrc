# $NetBSD: Makefile,v 1.25 2002/10/24 10:23:07 bouyer Exp $

DISTNAME=	opera-5.0.1
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/${OPERA_DIR}/ \
		ftp://ftp.opera.com/pub/opera/${OPERA_DIR}/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/opera/${OPERA_DIR}/
DISTFILES=	${OPERAFILE}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.opera.com/
COMMENT=	Small, fast and customizable WWW client

ONLY_FOR_PLATFORM=	NetBSD-*-i386 SunOS-*-sparc

LICENSE=	opera-license

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD && ${MACHINE_ARCH} == i386)
# we need the DIST_SUBDIR=. because of the inclusion of suse's Makefile.common
DIST_SUBDIR=	.
EXTRACT_ONLY=	# empty
NO_BUILD=	YES
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

DEPENDS+=	suse_compat>=6.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_libjpeg>=6.4:../../emulators/${SUSE_DIR_PREFIX}_libjpeg
DEPENDS+=	suse_libpng>=6.4:../../emulators/${SUSE_DIR_PREFIX}_libpng
DEPENDS+=	suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11

OPERA_ARCH=	${MACHINE_ARCH}
OPERA_DIR= 	linux/500
OPERAFILE=	opera-static-5.0-1.${OPERA_ARCH}.rpm
RPMFILES=	${OPERAFILE}
post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/bin/opera ${PREFIX}/bin
.include "../../emulators/suse_linux/Makefile.application"

.elif (${OPSYS} == NetBSD && ${MACHINE_ARCH} == powerpc)
DEPENDS+=	linuxppc_lib>=2000.4.2:../../emulators/linuxppc_lib

OPERA_ARCH=	ppc

.elif (${OPSYS} == SunOS && ${MACHINE_ARCH} == sparc)
OPERA_ARCH=	sparc
OPERA_DIR=	unix/solaris
OPERAFILE=	opera-5.0-b1-20010618.003-static.solaris.sparc.tar.gz
DISTNAME=	opera-5.0b1

PLIST_SRC=	PLIST.SunOS

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/opera.sh > ${WRKDIR}/opera

do-install:
	cd ${WRKDIR}/opera-5.0-b1-20010618.003-static.solaris.sparc && \
	./install.sh --prefix=${PREFIX} --docdir=${PREFIX}/share/doc/opera
	mv ${PREFIX}/bin/opera ${PREFIX}/libexec/opera
	${INSTALL_SCRIPT} ${WRKDIR}/opera ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
.endif

