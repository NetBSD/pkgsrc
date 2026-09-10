# $NetBSD: Makefile,v 1.18 2026/09/10 12:10:27 adam Exp $

DISTNAME=	python_swiftclient-4.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-swiftclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openstack/python-swiftclient
COMMENT=	Python bindings to the OpenStack Object Storage API
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=6.0.0:../../devel/py-pbr
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.0:../../devel/py-requests

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	fixing man path
SUBST_FILES.manpath=	setup.cfg
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	swift

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx via py-pbr

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} ${PKGMANDIR}/man1/swift.1 ${PKGMANDIR}/man1/swift-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
