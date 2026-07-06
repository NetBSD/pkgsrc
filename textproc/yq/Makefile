# $NetBSD: Makefile,v 1.20 2026/07/06 12:28:46 adam Exp $

DISTNAME=	yq-4.1.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kislyuk.github.io/yq/
COMMENT=	Command-line YAML and XML processor
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	jq-[0-9]*:../../devel/jq
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.8.1:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.6:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.11.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
