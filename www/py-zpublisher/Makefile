# $NetBSD: Makefile,v 1.2 2000/10/22 20:01:54 tsarna Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-zpublisher-2.2.2
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://classic.zope.org:8080/Documentation/Reference/ORB

DEPENDS+=	py-extclass>=2.2.2:../../lang/python

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EXTRACT_ELEMENTS=	${DISTNAME}/lib/python/ZPublisher

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/python

do-build:
	(cd ${WRKSRC}/..; ${PY_PROG} ${PY_LIBDIR}/compileall.py .)
	(cd ${WRKSRC}/..; ${PY_PROG} -O ${PY_LIBDIR}/compileall.py .)

do-install:
	${INSTALL_SCRIPT_DIR} ${PY_SITEPKG}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}; ${PAX} -r -w -v -p e ZPublisher ${PY_SITEPKG})
	${CHMOD} 755 ${PY_SITEPKG}/ZPublisher/Test.py
	(cd ${PREFIX}; ${FIND} ${PY_SITEPATH}/ZPublisher \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PY_SITEPATH}/ZPublisher \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	${LN} -sf ../${PY_SITEPATH}/ZPublisher/Test.py ${PREFIX}/bin/bobo

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
