# New ports collection Makefile for: Xaw3d
# Version required:	1.3
# Date created:         30th November 1997
# Whom:                 tron@lyssa.owl.de, soren@t.dk
#
# $NetBSD: Makefile,v 1.8 1998/01/29 16:52:14 tron Exp $
# FreeBSD Id: Makefile,v 1.14 1997/06/19 09:33:26 asami Exp
#

DISTNAME=	Xaw3d-1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	widgets/Xaw3d/R6.1

MAINTAINER=	tron@netbsd.org

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xc/lib/Xaw3d

post-extract:
	@(cd ${WRKSRC};ln -s .. X11)

post-install:
	${LDCONFIG} -m ${PREFIX}/lib || /usr/bin/true
	${MKDIR} ${PREFIX}/share/doc/Xaw3d
	${CP} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d

.include <bsd.port.mk>
