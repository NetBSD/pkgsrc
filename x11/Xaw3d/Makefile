# $NetBSD: Makefile,v 1.13 1998/06/05 12:06:12 frueauf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/06/19 09:33:26 asami Exp
#

DISTNAME=	Xaw3d-1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	widgets/Xaw3d/R6.1

MAINTAINER=	tron@netbsd.org

CONFLICTS=	Xaw-Xpm-1.1

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

.include "../../mk/bsd.pkg.mk"
