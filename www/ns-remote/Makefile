# $NetBSD: Makefile,v 1.28 2005/12/05 20:51:13 rillig Exp $

DISTNAME=	ns-remote
PKGNAME=	ns-remote-1.11
CATEGORIES=	www
MASTER_SITES=	http://home.netscape.com/newsref/std/
DISTFILES=	remote.c vroot.h

MAINTAINER=	norm@mono.org
HOMEPAGE=	http://home.netscape.com/newsref/std/x-remote.html
COMMENT=	Remote-control of Netscape and Mozilla-based browsers

DIST_SUBDIR=	netscape

LDFLAGS.SunOS+=	-lsocket -lnsl

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
