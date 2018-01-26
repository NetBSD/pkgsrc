# $NetBSD: Makefile,v 1.2 2018/01/26 17:20:08 triaxx Exp $

DISTNAME=	python-swiftclient-3.4.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-swiftclient/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/openstack/python-swiftclient
COMMENT=	Python bindings to the OpenStack Object Storage API
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	35 36

DEPENDS+= ${PYPKGPREFIX}-futures>=3.1:../../devel/py-futures
DEPENDS+= ${PYPKGPREFIX}-keystone>=0.7.0:../../emulators/py-keystone
DEPENDS+= ${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests
DEPENDS+= ${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	fixing man path
SUBST_FILES.manpath=	setup.cfg
SUBST_SED.manpath=	-e 's,@PKGMANDIR@,${PKGMANDIR},'

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
