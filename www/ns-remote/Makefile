# $NetBSD: Makefile,v 1.2 2000/01/13 05:12:15 simonb Exp $

DISTNAME=	ns-remote
PKGNAME=	ns-remote-1.1
CATEGORIES=	www
MASTER_SITES=	http://home.netscape.com/newsref/std/
DISTFILES=	remote.c vroot.h

MAINTAINER=	norm@mono.org
HOMEPAGE=	http://home.netscape.com/newsref/std/x-remote.html

# fill in when done...
# DEPENDS+=	../communicator
DIST_SUBDIR=    netscape
USE_X11=	yes

do-extract:
	${MKDIR} ${WRKSRC}
.for distfile in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${distfile} ${WRKSRC}
.endfor
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns-remote ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/ns-open ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
