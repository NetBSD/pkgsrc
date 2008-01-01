# $NetBSD: Makefile,v 1.34 2008/01/01 16:45:35 abs Exp $

DISTNAME=	ns-remote
PKGNAME=	ns-remote-1.11
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://home.netscape.com/newsref/std/
DISTFILES=	remote.c vroot.h

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.netscape.com/newsref/std/x-remote.html
COMMENT=	Remote-control of Netscape and Mozilla-based browsers

DIST_SUBDIR=	netscape

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
.for distfile in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${distfile} ${WRKSRC}
.endfor
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns-remote ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/ns-open ${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
