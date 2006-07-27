# $NetBSD: Makefile,v 1.1.1.1 2006/07/27 13:58:53 joerg Exp $
#

DISTNAME=		cmTemplate-0.3.2
PKGNAME=     		${PYPKGPREFIX}-cmTemplate-0.3.2
CATEGORIES=		textproc python
MASTER_SITES=		http://www.bouncingchairs.net/oss/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.bouncingchairs.net/oss/
COMMENT=		Simple and fast Python template engine

PY_PATCHPLIST=	# empty
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

do-build:
	${PYTHONBIN} ${PYCOMPILEALL} -l ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.py ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.pyc ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PYPKGPREFIX}-cmTemplate
	${INSTALL_DATA} ${WRKSRC}/doc/cmTemplate.html ${PREFIX}/share/doc/${PYPKGPREFIX}-cmTemplate

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
