# $NetBSD: Makefile,v 1.1.1.1 2003/01/05 04:13:43 rh Exp $
#

DISTNAME=	${PLUGGER}-linux-x86-glibc
PKGNAME=	moz-linux-${PLUGGER}
WRKSRC=		${WRKDIR}/${PLUGGER}
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://fredrik.hubbe.net/plugger.html
COMMENT=	streaming multimedia plugin for Mozilla (Linux version)

DEPENDS+=	mozilla-linux-[0-9]*:../../www/mozilla-linux

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
