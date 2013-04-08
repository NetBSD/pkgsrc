# $NetBSD: Makefile,v 1.22 2013/04/08 11:17:26 rodent Exp $

DISTNAME=	xdaemon-1.2
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	Daemon.README ${IMAGES:=_bw.xbm} ${IMAGES:=_color.xpm} \
		${IMAGES:=_icon.xbm} ${IMAGES:=_mask.xbm}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	BSD Daemon sticking on your desktop (like xteddy)

DEPENDS+=	xteddy-1.*:../../x11/xteddy

CONFLICTS+=	xdaemon-2.*

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	xdaemon

IMAGES=		xdaemon xdaemon2 xnetbsd-flag xnetbsd-flag2

INSTALLATION_DIRS=	bin share/doc share/xteddy/pixmaps

do-extract:
	@${MKDIR} ${WRKSRC}
	@${ECHO} Bringing daemonic powers to you!

do-install:
.for img in ${IMAGES}
.for sufx in _bw.xbm _color.xpm _icon.xbm _mask.xbm
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${img}${sufx} ${DESTDIR}${PREFIX}/share/xteddy/pixmaps/${img}${sufx}
.endfor # sufx
	${RM} -f ${DESTDIR}${PREFIX}/bin/${img}
	${LN} -s xteddy ${DESTDIR}${PREFIX}/bin/${img}
.endfor # img
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Daemon.README ${DESTDIR}${PREFIX}/share/doc/xdaemon.README

.include "../../mk/bsd.pkg.mk"
