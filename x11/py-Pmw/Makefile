# $NetBSD: Makefile,v 1.17 2004/10/03 00:18:37 tv Exp $
#

DISTNAME=	Pmw.0.8.5
PKGNAME=	${PYPKGPREFIX}-Pmw-0.8.5
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	Python meta widgets

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

WRKSRC=		${WRKDIR}/Pmw
USE_BUILDLINK3=	YES

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
.include "../../mk/bsd.pkg.mk"
