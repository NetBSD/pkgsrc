# $NetBSD: Makefile,v 1.6 2014/01/25 10:30:23 wiz Exp $

DISTNAME=	cmTemplate-0.3.2
PKGNAME=	${PYPKGPREFIX}-cmTemplate-0.3.2
CATEGORIES=	textproc python
MASTER_SITES=	http://www.bouncingchairs.net/oss/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bouncingchairs.net/oss/
COMMENT=	Simple and fast Python template engine

PY_PATCHPLIST=	# empty
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.3.2

INSTALLATION_DIRS=	${PYSITELIB} share/doc/${PYPKGPREFIX}-cmTemplate

do-build:
	${PY_COMPILE_ALL} -l ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.py ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/cmTemplate.pyc ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/doc/cmTemplate.html ${DESTDIR}${PREFIX}/share/doc/${PYPKGPREFIX}-cmTemplate

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
