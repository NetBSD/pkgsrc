#	$NetBSD: Makefile,v 1.1.1.1 2000/11/01 19:35:09 itojun Exp $

DISTNAME=	xscribble
PKGNAME=	xscribble-20000616
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/pub/apps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.handhelds.org/projects/xscribble.html

USE_IMAKE=	YES
NO_INSTALL_MANPAGES=	YES

MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX},g" <${PKGDIR}/MESSAGE >${MESSAGE_FILE}

post-install:
	${MKDIR} ${PREFIX}/share/examples/xscribble
	${CP} ${WRKSRC}/classifiers/*.cl ${PREFIX}/share/examples/xscribble

.include "../../mk/bsd.pkg.mk"
