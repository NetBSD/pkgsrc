# $NetBSD: Makefile,v 1.9 2003/07/17 22:56:01 grant Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-zpublisher-2.2.2
WRKSRC=		${WRKDIR}/${DISTNAME}/lib/python
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://classic.zope.org:8080/Documentation/Reference/ORB
COMMENT=	Publishes a collection of Python objects as Web resources

DEPENDS+=	py-extclass>=2.2.2:../../lang/py-extclass

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EXTRACT_ELEMENTS=	${DISTNAME}/lib/python/ZPublisher

do-build:
	cd ${WRKSRC}/.. && ${PY_PROG} ${PY_LIBDIR}/compileall.py .
	cd ${WRKSRC}/.. && ${PY_PROG} -O ${PY_LIBDIR}/compileall.py .

do-install:
	${INSTALL_SCRIPT_DIR} ${PY_SITEPKG}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe ZPublisher ${PY_SITEPKG}
	${CHMOD} 755 ${PY_SITEPKG}/ZPublisher/Test.py
	cd ${PREFIX} && ${FIND} ${PY_SITEPATH}/ZPublisher \
		-type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${PY_SITEPATH}/ZPublisher \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}
	${LN} -sf ../${PY_SITEPATH}/ZPublisher/Test.py ${PREFIX}/bin/bobo

.include "../../lang/python20/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
