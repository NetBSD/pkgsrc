# $NetBSD: Makefile,v 1.1.1.1 2000/08/22 11:02:12 rh Exp $
#

DISTNAME=		plugger-3.2-linux-x86-glibc
PKGNAME=		ns-${PLUGGERNAME}-${BINNAME}-${PLUGGERVERS}
WRKSRC=			${WRKDIR}/${PLUGGERFULL}
CATEGORIES=		www
MASTER_SITES=		http://fredrik.hubbe.net/plugger/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://fredrik.hubbe.net/plugger.html

BINNAME?=		common

.if ${BINNAME} != common
DEPENDS+=		${BINNAME}-*:../../www/${BINNAME}

MOZILLA_HOME=		${PREFIX}/lib/netscape/${NSNAME}
NS_VERS=		${NSNAME:C/.*-//}

PLIST_SUBST+=		NS_VERS=${NS_VERS} BINNAME=${BINNAME}
.endif

CONFLICTS+=		plugger-*	# obsolete all-in-one plugger package

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CONFIGURE=		YES
NO_BUILD=		YES

PLUGGERFULL=		${DISTNAME:C/-linux-x86-glibc//}
PLUGGERVERS=		${PLUGGERFULL:C/.*-//}
PLUGGERNAME=		${PLUGGERFULL:C/-.*//}
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

do-install:
.if ${BINNAME} != common
		cd ${WRKSRC} && \
		${INSTALL_DATA} pluggerrc ${MOZILLA_HOME}
.else
		cd ${WRKSRC} && \
		${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR} && \
		${INSTALL_PROGRAM} plugger.so ${NS_PLUGINS_DIR} && \
		${INSTALL_DATA} plugger.7 ${PREFIX}/man/man7 && \
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/plugger && \
		${INSTALL_DATA} README ${PREFIX}/share/doc/plugger && \
		${INSTALL_DATA} COPYING ${PREFIX}/share/doc/plugger
.endif

.include "../../mk/bsd.pkg.mk"

.if ${BINNAME} != common
NSNAME!=	( ${PKG_INFO} 2>/dev/null -e ${BINNAME} || ${ECHO} "" )
.endif
