# $NetBSD: Makefile,v 1.13 2006/03/01 22:44:04 wiz Exp $
#

DISTNAME=	${PLUGGER}-linux-x86-glibc
PKGNAME=	moz-bin-${PLUGGER}
PKGREVISION=	2
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
MOZILLA_HOME=	lib/mozilla-linux
LDD=		${PREFIX}/emul/linux/usr/bin/ldd

PLIST_SUBST+=	MOZILLA_HOME=${MOZILLA_HOME:Q}

INSTALLATION_DIRS=	emul/linux/etc emul/linux/usr/bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MOZILLA_HOME}/plugins
	${INSTALL_DATA} ${WRKSRC}/plugger.so ${PREFIX}/${MOZILLA_HOME}/plugins
	${INSTALL_DATA} ${WRKSRC}/pluggerrc ${PREFIX}/emul/linux/etc
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-4.0 ${PREFIX}/emul/linux/usr/bin

.include "../../mk/bsd.pkg.mk"
