# $NetBSD: Makefile,v 1.9 2004/01/20 12:28:28 agc Exp $

DISTNAME=	xdaemon-2.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	${PIX} Daemon.README

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	BSD Daemon sticking on your desktop (like xteddy)

DEPENDS+=	xteddy-2.*:../xteddy2

CONFLICT+=	xdaemon-1.*

#WRKSRC=	${WRKDIR}
DIST_SUBDIR=	xdaemon
PIX=		xdaemon.png xdaemon2.png
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${ECHO} Bringing daemonic powers to you!

do-install:
.for pic in ${PIX}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${pic} ${PREFIX}/share/xteddy/${pic}
.endfor
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Daemon.README ${PREFIX}/share/doc/xdaemon.README
	${LN} -s ${PREFIX}/bin/xteddy	${PREFIX}/bin/xdaemon
	${LN} -s ${PREFIX}/bin/xteddy	${PREFIX}/bin/xdaemon2

.include "../../mk/bsd.pkg.mk"
