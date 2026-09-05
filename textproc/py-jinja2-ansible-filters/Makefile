# $NetBSD: Makefile,v 1.2 2026/09/05 05:13:02 adam Exp $

DISTNAME=	jinja2-ansible-filters-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jinja2-ansible-filters/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/dreamer-labs/libraries/jinja2-ansible-filters
COMMENT=	Port of Ansible's jinja2 filters without requiring ansible core
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jinja2>=0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=   310 311 # py-yaml

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
