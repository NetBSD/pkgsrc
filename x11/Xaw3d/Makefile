# $NetBSD: Makefile,v 1.22 2001/02/17 17:06:13 wiz Exp $
#

DISTNAME=	Xaw3d-1.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=widgets/Xaw3d/R6.3/}

MAINTAINER=	packages@netbsd.org
COMMENT=	3-D widgets based on the Athena Widget set

CONFLICTS=	Xaw-Xpm-*

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
PLIST_SRC=	${WRKDIR}/PLIST-src
PLIST_SUBST=	XAWREV=${XAWREV}

post-extract:
	@(cd ${WRKSRC}; ${LN} -s .. X11)

post-install:
	${MKDIR} ${PREFIX}/share/doc/Xaw3d
	${CP} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d
	@if [ -f ${WRKSRC}/libXaw3d.a ]; then			\
		${CP} ${PKGDIR}/PLIST ${PLIST_SRC};		\
	else							\
		${SED} -e '/lib\/libXaw3d\.a/d'			\
			< ${PKGDIR}/PLIST > ${PLIST_SRC};	\
	fi

.include "../../mk/bsd.pkg.mk"

XAWREV!=awk '/define.*SharedXawRev/{print $$3}' ${X11BASE}/lib/X11/config/X11.tmpl
