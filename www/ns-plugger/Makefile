# $NetBSD: Makefile,v 1.1.1.1 2000/08/20 14:02:17 rh Exp $
#

DISTNAME=		plugger-3.2-linux-x86-glibc
PKGNAME=		${DISTNAME:C/-linux-x86-glibc//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		www
MASTER_SITES=		http://fredrik.hubbe.net/plugger/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://fredrik.hubbe.net/plugger.html

DEPENDS+=		{navigator,communicator}-*:../../www/navigator

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_VERS=		${NSNAME:C/.*-//}
BINNAME=		${NSNAME:C/-.*//}
MOZILLA_HOME=		${PREFIX}/lib/netscape/${NSNAME}
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

PLIST_SUBST+=		NS_VERS=${NS_VERS} BINNAME=${BINNAME}

do-install:
		cd ${WRKSRC} && \
		${INSTALL_PROGRAM} plugger.so ${NS_PLUGINS_DIR} && \
		${INSTALL_DATA} pluggerrc ${MOZILLA_HOME} && \
		${INSTALL_DATA} plugger.7 ${PREFIX}/man/man7 && \
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/plugger && \
		${INSTALL_DATA} README ${PREFIX}/share/doc/plugger && \
		${INSTALL_DATA} COPYING ${PREFIX}/share/doc/plugger && \

.include "../../mk/bsd.pkg.mk"

NSNAME!=		( ${PKG_INFO} 2>/dev/null communicator || \
			  ${PKG_INFO} 2>/dev/null navigator ) | \
			${HEAD} -n 1 | ${CUT} -d: -f1 | ${CUT} -d' ' -f 3
