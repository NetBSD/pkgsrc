# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:41 jlam Exp $
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
NO_CONFIGURE=	YES
NO_BUILD=	YES

PLUGGER_VERSION=4.0
PLUGGER=	plugger-${PLUGGER_VERSION}
MOZILLA_HOME=	${PREFIX}/lib/mozilla-linux
LDD=		${PREFIX}/emul/linux/usr/bin/ldd

INSTALLATION_DIRS=	emul/linux/etc emul/linux/usr/bin

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_DATA_DIR} ${MOZILLA_HOME}/plugins			\
	${INSTALL_DATA} plugger.so ${MOZILLA_HOME}/plugins &&		\
	${INSTALL_DATA} pluggerrc ${PREFIX}/emul/linux/etc &&		\
	${INSTALL_PROGRAM} plugger-4.0 ${PREFIX}/emul/linux/usr/bin

.include "../../mk/bsd.pkg.mk"
