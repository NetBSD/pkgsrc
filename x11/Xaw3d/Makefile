# $NetBSD: Makefile,v 1.24 2001/03/11 09:45:40 tron Exp $
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

.include "../../mk/bsd.prefs.mk"

post-extract:
	@(cd ${WRKSRC}; ${LN} -s .. X11)

.if (${OPSYS} == SunOS) && (${X11BASE} == /usr/openwin)
post-configure:
	cd ${WRKSRC}; \
	${SED} -e 's#^	SERVER#SERVER#' <${MAKEFILE} >${MAKEFILE}.sed; \
	${MV} ${MAKEFILE}.sed ${MAKEFILE}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Xaw3d
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${PREFIX}/share/doc/Xaw3d
	@if [ -f ${WRKSRC}/libXaw3d.a ]; then			\
		${CP} ${PKGDIR}/PLIST ${PLIST_SRC};		\
	else							\
		${SED} -e '/lib\/libXaw3d\.a/d'			\
			< ${PKGDIR}/PLIST > ${PLIST_SRC};	\
	fi

.include "../../mk/bsd.pkg.mk"

.if (${OPSYS} == SunOS) && (${X11BASE} == /usr/openwin)
XAWREV!=awk '/define.*SharedXawRev/{print $$3}' ${X11BASE}/lib/config/sv4Lib.tmpl
.else
XAWREV!=awk '/define.*SharedXawRev/{print $$3}' ${X11BASE}/lib/X11/config/X11.tmpl
.endif
