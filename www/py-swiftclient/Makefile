# $NetBSD: Makefile,v 1.12 2023/11/15 11:51:09 wiz Exp $

DISTNAME=	python-swiftclient-3.11.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-swiftclient/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/openstack/python-swiftclient
COMMENT=	Python bindings to the OpenStack Object Storage API
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	fixing man path
SUBST_FILES.manpath=	setup.cfg
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/swift bin/swift-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/swift.1 ${PKGMANDIR}/man1/swift-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
