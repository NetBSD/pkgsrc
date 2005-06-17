# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:41 jlam Exp $

DISTNAME=		plugger-4.0-linux-x86-glibc
PKGNAME=		ns-${PLUGGERNAME}-${BINNAME}-${PLUGGERVERS}
CATEGORIES=		www
MASTER_SITES=		http://fredrik.hubbe.net/plugger/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://fredrik.hubbe.net/plugger.html
COMMENT=		Streaming multimedia plugin for Netscape

BINNAME?=		common

.if ${BINNAME} != common
DEPENDS+=		${BINNAME}-[0-9]*:../../www/${BINNAME}
MOZILLA_HOME=		${PREFIX}/lib/netscape/${NSNAME:C/nb[0-9]+$//:S/4.80/4.8/}
PLIST_SUBST+=		MOZILLA_HOME=${MOZILLA_HOME:S/${PREFIX}\///}
.else
DEPENDS+=		suse_base>=6.3:../../emulators/${SUSE_DIR_PREFIX}_base
.endif

CONFLICTS+=		plugger-[0-9]*	# obsolete all-in-one plugger package

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}/${PLUGGERFULL}
NO_CONFIGURE=		YES
NO_BUILD=		YES

PLUGGERFULL=		${DISTNAME:C/-linux-x86-glibc//}
PLUGGERVERS=		${PLUGGERFULL:C/.*-//}
PLUGGERNAME=		${PLUGGERFULL:C/-.*//}
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins
DOCDIR=			${PREFIX}/share/doc/plugger

PLIST_SUBST+=		NS_PLUGINS_DIR=${NS_PLUGINS_DIR:S/${PREFIX}\///}

CHECK_SHLIBS=		no
INSTALLATION_DIRS=	bin man/man7

do-install:
.if ${BINNAME} != common
	cd ${WRKSRC}; ${INSTALL_DATA} pluggerrc ${MOZILLA_HOME}/pluggerrc
.else
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_PROGRAM} plugger.so ${NS_PLUGINS_DIR}
	cd ${WRKSRC}; ${INSTALL_PROGRAM} plugger-4.0 ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} plugger.7 ${PREFIX}/man/man7
	cd ${WRKSRC}; ${INSTALL_DATA} README COPYING ${DOCDIR}
.endif

.include "../../emulators/suse_linux/Makefile.application"

.if ${BINNAME} != common
NSNAME!=	${PKG_INFO} -e ${BINNAME} || ${ECHO}
.endif

.include "../../mk/bsd.pkg.mk"
