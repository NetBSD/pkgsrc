# $NetBSD: Makefile,v 1.3 1999/04/06 14:58:50 agc Exp $

DISTNAME=		Eterm-0.8.8
PKGNAME=		eterm-0.8.8
CATEGORIES=		x11
MASTER_SITES=		http://www.eterm.org/download/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			Eterm-bg-scale-1.tar.gz Eterm-bg-scale-2.tar.gz \
			Eterm-bg-tile.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.eterm.org/

DEPENDS+=		imlib-1.9.4:../../graphics/imlib

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes

post-extract:
	${MV} ${WRKDIR}/Eterm/bg/scale/* ${WRKSRC}/bg/scale
	${MV} ${WRKDIR}/Eterm/bg/tile/* ${WRKSRC}/bg/tile
	${RM} -r ${WRKDIR}/Eterm
	${CHMOD} -R o+r ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
