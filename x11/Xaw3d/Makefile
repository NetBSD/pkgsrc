# $NetBSD: Makefile,v 1.27 2001/06/07 16:23:10 tron Exp $
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
PLIST_SUBST=	XAWREV=${XAWREV} XAWMAJOR=${XAWMAJOR}

.include "../../mk/bsd.prefs.mk"

post-extract:
	@(cd ${WRKSRC}; ${LN} -s .. X11)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Xaw3d
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d
	@if [ -f ${WRKSRC}/libXaw3d.a ]; then			\
		${CP} ${PKGDIR}/PLIST ${PLIST_SRC};		\
	else							\
		${SED} -e '/lib\/libXaw3d\.a/d'			\
			< ${PKGDIR}/PLIST > ${PLIST_SRC};	\
	fi
.if (${OPSYS} == SunOS)
	${RM} -f ${PREFIX}/lib/libXaw3d.so.${XAWMAJOR}
	${LN} -s libXaw3d.so.${XAWREV} ${PREFIX}/lib/libXaw3d.so.${XAWMAJOR}
.endif

.include "../../mk/bsd.pkg.mk"

.if (${OPSYS} == SunOS) && (${X11BASE} == /usr/openwin)
XAWREV!=	awk '/define.*SharedXawRev/{print $$3}' ${X11BASE}/lib/config/sv4Lib.tmpl
.else
XAWREV!=	awk '/define.*SharedXawRev/{print $$3}' ${X11BASE}/lib/X11/config/X11.tmpl
.endif
XAWMAJOR=	${XAWREV:C/\..*//}
