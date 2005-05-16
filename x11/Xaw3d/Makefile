# $NetBSD: Makefile,v 1.44 2005/05/16 18:45:29 jlam Exp $
#

DISTNAME=	Xaw3d-1.5E
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.visi.com/~hawkeyd/xaw3d.html
COMMENT=	3-D widgets based on the Athena Widget set

CONFLICTS=	Xaw-Xpm-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	YES
PLIST_SRC=	${WRKDIR}/PLIST-src

.include "../../mk/bsd.prefs.mk"

.if empty(X11BASE:M*openwin)
post-extract:
	@(cd ${WRKSRC}; ${LN} -s .. X11)
.else
IMAKE_FLAGS+=	-DXISOPENWIN
.endif

XMKMF_FLAGS+=	${IMAKE_FLAGS}

PLIST_SUBST+=	INCDIR=include/X11

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
