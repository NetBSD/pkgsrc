# $NetBSD: Makefile,v 1.9 2001/07/27 14:26:19 abs Exp $

DISTNAME=	ns-remote
PKGNAME=	ns-remote-1.4
CATEGORIES=	www
MASTER_SITES=	http://home.netscape.com/newsref/std/
DISTFILES=	remote.c vroot.h

MAINTAINER=	norm@mono.org
HOMEPAGE=	http://home.netscape.com/newsref/std/x-remote.html
COMMENT=	remote-control Netscape Navigator and Communicator

DIST_SUBDIR=    netscape
USE_X11=	yes

USE_BUILDLINK_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
LDFLAGS+=	-lsocket -lnsl
.endif

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
