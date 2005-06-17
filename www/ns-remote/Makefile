# $NetBSD: Makefile,v 1.26 2005/06/17 03:50:41 jlam Exp $

DISTNAME=	ns-remote
PKGNAME=	ns-remote-1.10
CATEGORIES=	www
MASTER_SITES=	http://home.netscape.com/newsref/std/
DISTFILES=	remote.c vroot.h

MAINTAINER=	norm@mono.org
HOMEPAGE=	http://home.netscape.com/newsref/std/x-remote.html
COMMENT=	Remote-control of Netscape and Mozilla-based browsers

DIST_SUBDIR=	netscape

LDFLAGS.SunOS=	-lsocket -lnsl

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

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
