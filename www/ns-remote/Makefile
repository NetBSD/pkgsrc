# $NetBSD: Makefile,v 1.22 2005/03/08 20:15:14 bad Exp $

DISTNAME=	ns-remote
PKGNAME=	ns-remote-1.9
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://home.netscape.com/newsref/std/
DISTFILES=	remote.c vroot.h

MAINTAINER=	norm@mono.org
HOMEPAGE=	http://home.netscape.com/newsref/std/x-remote.html
COMMENT=	Remote-control of Netscape and Mozilla-based browsers

DIST_SUBDIR=	netscape

USE_BUILDLINK3=	yes
USE_X11=	# defined

LDFLAGS.SunOS=	-lsocket -lnsl

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
