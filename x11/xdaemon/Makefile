# $NetBSD: Makefile,v 1.1.1.1 2000/01/05 05:03:24 hubertf Exp $

DISTNAME=	xdaemon-1.0
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
PIX=	xdaemon_bw.xbm		xdaemon2_bw.xbm \
	xdaemon_color.xpm	xdaemon2_color.xpm \
	xdaemon_icon.xbm	xdaemon2_icon.xbm \
	xdaemon_mask.xbm	xdaemon2_mask.xbm
DISTFILES=	${PIX} Daemon.README

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	xteddy-1.*:../xteddy

WRKSRC=		${WRKDIR}
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${ECHO} Bringing daemonic powers to you!

do-install:
.for pic in ${PIX}
	${INSTALL_DATA} ${DISTDIR}/${pic} ${PREFIX}/share/xteddy/pixmaps/${pic}
.endfor
	${INSTALL_DATA} ${DISTDIR}/Daemon.README ${PREFIX}/share/doc/xdaemon.README
	${LN}	${PREFIX}/bin/xteddy	${PREFIX}/bin/xdaemon
	${LN}	${PREFIX}/bin/xteddy	${PREFIX}/bin/xdaemon2

.include "../../mk/bsd.pkg.mk"
