# $NetBSD: Makefile,v 1.30 2022/02/05 09:00:25 adam Exp $

DISTNAME=	tornado-6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tornado/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://www.tornadoweb.org/
COMMENT=	Fast and non-blocking web framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-curl>=7.18.2:../../www/py-curl

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m tornado.test.runtests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
