# $NetBSD: Makefile,v 1.36 2004/01/20 12:28:26 agc Exp $
#

DISTNAME=	Xaw3d-1.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=widgets/Xaw3d/R6.3/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	3-D widgets based on the Athena Widget set

CONFLICTS=	Xaw-Xpm-[0-9]*

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_BUILDLINK2=	YES
USE_IMAKE=	YES
PLIST_SRC=	${WRKDIR}/PLIST-src

.include "../../mk/bsd.prefs.mk"

.if !empty(X11BASE:M*openwin) #|| ${OPSYS} == "IRIX"
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
.if ${OPSYS} == "IRIX"
	${INSTALL_DATA} /usr/lib${ABI}/libXaw3d* ${PREFIX}/lib/
	${RM} -f /usr/lib${ABI}/libXaw3d*
.endif
	cd ${PREFIX} && ${LS} lib/libXaw3d* >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
