# $NetBSD: Makefile,v 1.17 2015/12/23 12:43:50 joerg Exp $

DISTNAME=	tornado-4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/t/tornado/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.tornadoweb.org/
COMMENT=	Fast and non-blocking web framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-curl>=7.18.2:../../www/py-curl
DEPENDS+=	${PYPKGPREFIX}-backports_abc>=0.4:../../devel/py-backports_abc

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
.if "${PYPKGPREFIX}" == "py33"
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-singledispatch>0:../../devel/py-singledispatch
.endif
.if "${PYPKGPREFIX}" != "py35"
PLIST.requires=	yes
.endif

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
