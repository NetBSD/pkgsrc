# $NetBSD: Makefile,v 1.7 2014/07/22 12:41:28 wiz Exp $

DISTNAME=	tornado-4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/t/tornado/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.tornadoweb.org/
COMMENT=	Fast and non-blocking web framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-curl>=7.18.2:../../www/py-curl

REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	tornado/*.py
REPLACE_PYTHON+=	tornado/platform/*.py
REPLACE_PYTHON+=	tornado/test/*.py

do-test:
	${RUN}cd ${WRKSRC}; ${PYTHONBIN} -m tornado.test.runtests

.include "../../lang/python/pyversion.mk"

.if "${PYPKGPREFIX}" == "py26" || "${PYPKGPREFIX}" == "py27
DEPENDS+=	${PYPKGPREFIX}-backports.ssl_match_hostname-[0-9]*:../../security/py-backports.ssl_match_hostname
.endif

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
