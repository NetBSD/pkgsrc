# $NetBSD: Makefile,v 1.1.1.1 2000/07/28 17:51:15 tsarna Exp $
#

DISTNAME=	Zope-2.2.0-src
PKGNAME=	py-zpublisher-2.2.0
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://classic.zope.org:8080/Documentation/Reference/ORB

DEPENDS+=	py-extclass>=2.2.0:../../lang/python

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
SITE_PKG=		lib/python1.5/site-packages
PYTHON_LIBDIR=		${LOCALBASE}/${SITE_PKG}
EXTRACT_ELEMENTS=	${DISTNAME}/lib/python/ZPublisher

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/python

do-build:
	(cd ${WRKSRC}/..; ${LOCALBASE}/bin/python ${PREFIX}/lib/python1.5/compileall.py .)
	(cd ${WRKSRC}/..; ${LOCALBASE}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py .)

do-install:
	${INSTALL_SCRIPT_DIR} ${PYTHON_LIBDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}; ${PAX} -r -w -v -p e ZPublisher ${PYTHON_LIBDIR})
	${CHMOD} 755 ${PYTHON_LIBDIR}/ZPublisher/Test.py
	(cd ${PREFIX}; ${FIND} ${SITE_PKG}/ZPublisher \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${SITE_PKG}/ZPublisher \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})
	${LN} -sf ../${SITE_PKG}/ZPublisher/Test.py ${PREFIX}/bin/bobo

.include "../../mk/bsd.pkg.mk"
