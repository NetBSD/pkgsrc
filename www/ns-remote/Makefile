# $NetBSD: Makefile,v 1.14 2002/09/20 11:26:51 abs Exp $

DISTNAME=	ns-remote
PKGNAME=	ns-remote-1.7
CATEGORIES=	www
MASTER_SITES=	http://home.netscape.com/newsref/std/
DISTFILES=	remote.c vroot.h

MAINTAINER=	norm@mono.org
HOMEPAGE=	http://home.netscape.com/newsref/std/x-remote.html
COMMENT=	remote-control Netscape Navigator and Communicator

DIST_SUBDIR=    netscape

USE_BUILDLINK2=	# defined
USE_X11=	# defined

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
