# $NetBSD: Makefile,v 1.13 2025/04/20 22:19:11 wiz Exp $

DISTNAME=	posting-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/posting/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/darrenburns/posting
COMMENT=	Modern API client that lives in your terminal
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-click-default-group>=1.2.4:../../devel/py-click-default-group
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dotenv>=1.0.1:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.28.1:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-pydantic-settings>=2.4.0:../../devel/py-pydantic-settings
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.9.2:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-openapi-pydantic>=0.5.0:../../textproc/py-openapi-pydantic
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.9.0:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-textual-autocomplete>=4.0.4:../../comms/py-textual-autocomplete
DEPENDS+=	${PYPKGPREFIX}-textual>=3.0.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-watchfiles>=0.24.0:../../misc/py-watchfiles
DEPENDS+=	${PYPKGPREFIX}-xdg-base-dirs>=6.0.1:../../devel/py-xdg-base-dirs
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.2:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-textual-dev>=1.5.1:../../comms/py-textual-dev
TEST_DEPENDS+=	${PYPKGPREFIX}-test-textual-snapshot>=1.0.0:../../devel/py-test-textual-snapshot
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=5.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.4:../../textproc/py-jinja2
#    "syrupy>=4.6.1",
#    "pytest-xdist>=3.6.1",
#    "mkdocs-material>=9.5.30",
#    "pyinstrument>=5.0.1",

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

# as of 2.7.0
# 56 failed, 115 passed, 1 skipped, 1 warning

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} posting posting-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
