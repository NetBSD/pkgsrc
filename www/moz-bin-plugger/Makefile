# $NetBSD: Makefile,v 1.1.1.1 2003/04/19 03:50:50 rh Exp $
#

DISTNAME=	${PLUGGER}-linux-x86-glibc
PKGNAME=	moz-bin-${PLUGGER}
WRKSRC=		${WRKDIR}/${PLUGGER}
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://fredrik.hubbe.net/plugger.html
COMMENT=	streaming multimedia plugin for Mozilla (Linux version)

DEPENDS+=	mozilla-bin-[0-9]*:../../www/mozilla-bin
CONFLICTS+=	moz-linux-plugger-[0-9]*

USE_BUILDLINK2=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

PLUGGER_VERSION=4.0
PLUGGER=	plugger-${PLUGGER_VERSION}
MOZILLA_HOME=	${PREFIX}/lib/mozilla-linux
LDD=		${PREFIX}/emul/linux/usr/bin/ldd

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} plugger.so ${MOZILLA_HOME}/plugins &&		\
	${INSTALL_DATA} pluggerrc ${PREFIX}/emul/linux/etc &&		\
	${INSTALL_PROGRAM} plugger-4.0 ${PREFIX}/emul/linux/usr/bin

.include "../../mk/bsd.pkg.mk"
