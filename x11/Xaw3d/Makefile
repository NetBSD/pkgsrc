# $NetBSD: Makefile,v 1.50 2006/12/15 20:33:03 joerg Exp $
#

DISTNAME=	Xaw3d-1.5E
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.visi.com/~hawkeyd/xaw3d.html
COMMENT=	3-D widgets based on the Athena Widget set

CONFLICTS=	Xaw-Xpm-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/Xaw3d
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${DESTDIR}${PREFIX}/share/doc/Xaw3d
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.if ${OPSYS} == "IRIX"
	${INSTALL_DATA} /usr/lib${ABI}/libXaw3d* ${DESTDIR}${PREFIX}/lib/
	${RM} -f /usr/lib${ABI}/libXaw3d*
.endif
	cd ${DESTDIR}${PREFIX} && ${LS} lib/libXaw3d* >>${PLIST_SRC}

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
