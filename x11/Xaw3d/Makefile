# $NetBSD: Makefile,v 1.30 2002/11/14 10:04:46 jlam Exp $
#

DISTNAME=	Xaw3d-1.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=widgets/Xaw3d/R6.3/}

MAINTAINER=	packages@netbsd.org
COMMENT=	3-D widgets based on the Athena Widget set

CONFLICTS=	Xaw-Xpm-[0-9]*

USE_IMAKE=	YES
WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
PLIST_SRC=	${WRKDIR}/PLIST-src

.include "../../mk/bsd.prefs.mk"

.if !empty(X11BASE:M*openwin)
PLIST_SUBST+=	INCDIR=include/X11/X11
.else
PLIST_SUBST+=	INCDIR=include/X11
.endif

post-extract:
	@(cd ${WRKSRC}; ${LN} -s .. X11)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Xaw3d
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${PREFIX} && ${LS} lib/libXaw3d* >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
