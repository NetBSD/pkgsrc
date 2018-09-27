# $NetBSD: Makefile,v 1.6 2018/09/27 22:29:32 tnn Exp $

DISTNAME=	python-swiftclient-3.5.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-swiftclient/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/openstack/python-swiftclient
COMMENT=	Python bindings to the OpenStack Object Storage API
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-keystone>=0.7.0:../../emulators/py-keystone
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

.include "../../lang/python/pyversion.mk"

.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-futures>=3.1:../../devel/py-futures
.endif

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	fixing man path
SUBST_FILES.manpath=	setup.cfg
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/swift bin/swift${PYVERSSUFFIX} && \
	${MV} man/man1/swift.1 man/man1/swift${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
