# $NetBSD: Makefile,v 1.39 2005/02/18 15:54:48 wiz Exp $
#

DISTNAME=	Xaw3d-1.5E
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.visi.com/~hawkeyd/xaw3d.html
COMMENT=	3-D widgets based on the Athena Widget set

CONFLICTS=	Xaw-Xpm-[0-9]*

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_BUILDLINK3=	YES
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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
