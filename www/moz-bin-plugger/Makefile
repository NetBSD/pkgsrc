# $NetBSD: Makefile,v 1.5 2004/01/20 12:27:59 agc Exp $
#

DISTNAME=	${PLUGGER}-linux-x86-glibc
PKGNAME=	moz-bin-${PLUGGER}
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://fredrik.hubbe.net/plugger.html
COMMENT=	Streaming multimedia plugin for Mozilla (Linux version)

DEPENDS+=	mozilla-bin-[0-9]*:../../www/mozilla-bin

CONFLICTS+=	moz-linux-plugger-[0-9]*

WRKSRC=		${WRKDIR}/${PLUGGER}
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
