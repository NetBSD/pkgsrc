# $NetBSD: Makefile,v 1.6 2002/12/08 02:13:30 salo Exp $
#

DISTNAME=	Pmw.0.8.5
PKGNAME=	${PYPKGPREFIX}-Pmw-0.8.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	python meta widgets

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC
WRKSRC=		${WRKDIR}/Pmw

USE_BUILDLINK2=	YES

do-build:

do-install:
	(cd ${WRKDIR}; ${FIND} Pmw -type d | \
	    ${SED} -e 's,^,${PREFIX}/${PYSITELIB}/,' | ${XARGS} ${INSTALL_DATA_DIR})
	(cd ${WRKDIR}; for f in `${FIND} Pmw -type f`; do \
	    ${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}/$$f; done)
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} ${PYSITELIB}/Pmw \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PYSITELIB}/Pmw \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
