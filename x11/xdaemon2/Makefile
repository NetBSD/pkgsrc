# $NetBSD: Makefile,v 1.1.1.1 2000/12/05 22:58:04 hubertf Exp $

DISTNAME=	xdaemon-2.0
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	${PIX} Daemon.README

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.netbsd.org/

DEPENDS+=	xteddy-2.*:../xteddy

CONFLICT+=	xdaemon-1.*

DIST_SUBDIR=xdaemon
PIX=		xdaemon.png xdaemon2.png
#WRKSRC=	${WRKDIR}
NO_PATCH=	yes
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
