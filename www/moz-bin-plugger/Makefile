# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:25 joerg Exp $
#

DISTNAME=	${PLUGGER}-linux-x86-glibc
PKGNAME=	moz-bin-${PLUGGER}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://fredrik.hubbe.net/plugger.html
COMMENT=	Streaming multimedia plugin for Mozilla (Linux version)

BROKEN_IN=	pkgsrc-2005Q4

DEPENDS+=	mozilla-bin-[0-9]*:../../www/mozilla-bin

CONFLICTS+=	moz-linux-plugger-[0-9]*

WRKSRC=		${WRKDIR}/${PLUGGER}
NO_CONFIGURE=	YES
NO_BUILD=	YES

PLUGGER_VERSION=4.0
PLUGGER=	plugger-${PLUGGER_VERSION}
MOZILLA_HOME=	${PREFIX}/lib/mozilla-linux
LDD=		${PREFIX}/emul/linux/usr/bin/ldd

PLIST_SUBST+=	MOZILLA_HOME=${MOZILLA_HOME:Q}

INSTALLATION_DIRS=	emul/linux/etc emul/linux/usr/bin

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_DATA_DIR} ${MOZILLA_HOME}/plugins			\
	${INSTALL_DATA} plugger.so ${MOZILLA_HOME}/plugins &&		\
	${INSTALL_DATA} pluggerrc ${PREFIX}/emul/linux/etc &&		\
	${INSTALL_PROGRAM} plugger-4.0 ${PREFIX}/emul/linux/usr/bin

.include "../../mk/bsd.pkg.mk"
