# $NetBSD: Makefile,v 1.24 2013/12/23 11:57:06 wiz Exp $

DISTNAME=		plugger-4.0-linux-x86-glibc
PKGNAME=		ns-${PLUGGERNAME}-${BINNAME}-${PLUGGERVERS}
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://fredrik.hubbe.net/plugger/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fredrik.hubbe.net/plugger.html
COMMENT=		Streaming multimedia plugin for Netscape

CONFLICTS+=		plugger-[0-9]*	# obsolete all-in-one plugger package

BINNAME?=		common

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}/${PLUGGERFULL}
BUILD_DIRS=		# empty

PLUGGERFULL=		${DISTNAME:C/-linux-x86-glibc//}
PLUGGERVERS=		${PLUGGERFULL:C/.*-//}
PLUGGERNAME=		${PLUGGERFULL:C/-.*//}
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins
DOCDIR=			${PREFIX}/share/doc/plugger

PLIST_SUBST+=		NS_PLUGINS_DIR=${NS_PLUGINS_DIR:S/${PREFIX}\///}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man7
INSTALLATION_DIRS+=	lib/netscape/plugins share/doc/plugger

.PHONY: do-install-common do-install-pluggerrc
do-install-common:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} plugger.so ${DESTDIR}${NS_PLUGINS_DIR}
	cd ${WRKSRC}; ${INSTALL_PROGRAM} plugger-4.0 ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} plugger.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	cd ${WRKSRC}; ${INSTALL_DATA} README COPYING ${DESTDIR}${DOCDIR}

do-install-pluggerrc:
	cd ${WRKSRC}; ${INSTALL_DATA} pluggerrc ${DESTDIR}${MOZILLA_HOME}/pluggerrc

.if ${BINNAME} == "common"
do-install: do-install-common
.else
do-install: do-install-common
.endif

.include "../../mk/bsd.pkg.mk"

.if ${BINNAME} != common
DEPENDS+=		${BINNAME}-[0-9]*:../../www/${BINNAME}
NSNAME!=		${PKG_INFO} -e ${BINNAME} || ${ECHO}
MOZILLA_HOME=		${PREFIX}/lib/netscape/${NSNAME:C/nb[0-9]+$//:S/4.80/4.8/}
PLIST_SUBST+=		MOZILLA_HOME=${MOZILLA_HOME:S/${PREFIX}\///}
.endif
