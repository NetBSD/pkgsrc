# $NetBSD: Makefile,v 1.5.4.1 2002/07/22 17:07:43 agc Exp $

DISTNAME=	xdaemon-2.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	${PIX} Daemon.README

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.netbsd.org/
COMMENT=	BSD Daemon sticking on your desktop (like xteddy)

DEPENDS+=	xteddy-2.*:../xteddy2

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy
.for pic in ${PIX}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${pic} ${PREFIX}/share/xteddy/${pic}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Daemon.README ${PREFIX}/share/doc/xdaemon.README
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/xteddy	${PREFIX}/bin/xdaemon
	${LN} -s ${PREFIX}/bin/xteddy	${PREFIX}/bin/xdaemon2

.include "../../mk/bsd.pkg.mk"
