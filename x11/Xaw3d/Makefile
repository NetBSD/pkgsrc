# New ports collection Makefile for: Xaw3d
# Version required:	1.3
# Date created:         30th November 1997
# Whom:                 tron@lyssa.owl.de, soren@t.dk
#
# $NetBSD: Makefile,v 1.11 1998/03/12 00:58:06 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/06/19 09:33:26 asami Exp
#

DISTNAME=	Xaw3d-1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	widgets/Xaw3d/R6.1

MAINTAINER=	tron@netbsd.org

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
PLIST_SRC=	${WRKDIR}/PLIST-src

post-extract:
	@(cd ${WRKSRC}; ${LN} -s .. X11)

post-install:
	${LDCONFIG} || ${TRUE}
	${MKDIR} ${PREFIX}/share/doc/Xaw3d
	${CP} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d
	@if [ -f ${WRKSRC}/libXaw3d.a ]; then			\
		${CP} ${PKGDIR}/PLIST ${PLIST_SRC};		\
	else							\
		${SED} -e '/lib\/libXaw3d\.a/d'			\
			< ${PKGDIR}/PLIST > ${PLIST_SRC};	\
	fi

.include <bsd.port.mk>
