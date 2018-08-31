# $NetBSD: Makefile,v 1.26 2018/08/31 09:51:06 adam Exp $

DISTNAME=	tornado-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tornado/}

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

PLIST_VARS+=	requires
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-backports.ssl_match_hostname-[0-9]*:../../security/py-backports.ssl_match_hostname
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-singledispatch>0:../../devel/py-singledispatch
.endif
.if "${PYPKGPREFIX}" == "py27" || "${PYPKGPREFIX}" == "py34"
DEPENDS+=	${PYPKGPREFIX}-backports_abc>=0.4:../../devel/py-backports_abc
PLIST.requires=	yes
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
