# $NetBSD: Makefile,v 1.19 2005/10/07 17:44:27 perry Exp $
#

DISTNAME=	Pmw.1.2
PKGNAME=	${PYPKGPREFIX}-Pmw-1.2
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	Python meta widgets

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

WRKSRC=		${WRKDIR}/Pmw

do-build:

do-install:
	(cd ${WRKDIR}; ${FIND} Pmw -type d -print | \
	    ${SED} -e 's,^,${PREFIX}/${PYSITELIB}/,' | ${XARGS} -n 1 ${INSTALL_DATA_DIR})
	(cd ${WRKDIR}; for f in `${FIND} Pmw -type f -print`; do \
	    ${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}/$$f; done)
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} ${PYSITELIB}/Pmw \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PYSITELIB}/Pmw \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
