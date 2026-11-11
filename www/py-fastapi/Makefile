# $NetBSD: Makefile,v 1.1 2026/11/11 15:45:12 wiz Exp $

DISTNAME=	fastapi-0.162.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastapi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://fastapi.tiangolo.com/
COMMENT=	Modern, fast (high-performance), web framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-starlette>=0.46.0:../../www/py-starlette
DEPENDS+=	${PYPKGPREFIX}-anyio>=4.1.0:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.9.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.8.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-typing-inspection>=0.4.2:../../devel/py-typing-inspection
DEPENDS+=	${PYPKGPREFIX}-annotated-doc>=0.0.2:../../textproc/py-annotated-doc
DEPENDS+=	${PYPKGPREFIX}-opentelemetry-api>=1.44.0:../../devel/py-opentelemetry-api
# enable 'standard' dependencies
DEPENDS+=	${PYPKGPREFIX}-opentelemetry-sdk>=1.44.0:../../devel/py-opentelemetry-sdk
# currently unpackaged:
# "opentelemetry-exporter-otlp-proto-http>=1.44.0",
# "fastapi-cli[standard] >=0.0.32",
# "fastar >= 0.9.0",
# DEPENDS+=	${PYPKGPREFIX}-pydantic-extra-types>=2.0.0:../../devel/py-pydantic-extra-types
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.23.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-httpx2>=2.0.0:../../www/py-httpx2
DEPENDS+=	${PYPKGPREFIX}-jinja2>=1.3.5:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-python-multipart>=0.0.18:../../www/py-python-multipart
DEPENDS+=	${PYPKGPREFIX}-email_validator>=2.0.0:../../mail/py-email_validator
DEPENDS+=	${PYPKGPREFIX}-uvicorn>=0.12.0:../../www/py-uvicorn
DEPENDS+=	${PYPKGPREFIX}-pydantic-settings>=2.0.0:../../devel/py-pydantic-settings
TEST_DEPENDS+=	${PYPKGPREFIX}-inline-snapshot-[0-9]*:../../devel/py-inline-snapshot
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals-[0-9]*:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-JWT-[0-9]*:../../textproc/py-JWT
TEST_DEPENDS+=	${PYPKGPREFIX}-pwdlib>=0:../../security/py-pwdlib
TEST_DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0:../../databases/py-sqlalchemy
TEST_DEPENDS+=	${PYPKGPREFIX}-typer-[0-9]*:../../devel/py-typer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=0:../../devel/py-coverage
# unpackaged: strawberry
# more test pass when these are _not_ enabled:
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
#TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
#TEST_DEPENDS+=	${PYPKGPREFIX}-anyio-[0-9]*:../../devel/py-anyio
#TEST_DEPENDS+=	${PYPKGPREFIX}-ujson-[0-9]*:../../textproc/py-ujson
#TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# used by some tests:
# logfire
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
# opentelemetry.exporter

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	fastapi

USE_TOOLS+=	git:test

# as of 0.162.4
# 45 failed, 4653 passed, 19 skipped, 6 errors

# these test scripts break collection by pytest
pre-test:
# problem with 'scripts' (from this module?)
	${RM} -f ${WRKSRC}/scripts/tests/test_remove_unused_docs_src.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_code_blocks/test_code_blocks_lines_number_mismatch.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_code_blocks/test_code_blocks_mermaid.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_code_blocks/test_code_blocks_number_mismatch.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_code_blocks/test_code_blocks_wrong_lang_code.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_code_includes/test_number_mismatch.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_complex_doc/test_compex_doc.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_header_permalinks/test_header_level_mismatch.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_header_permalinks/test_header_number_mismatch.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_html_links/test_html_links_number_mismatch.py
	${RM} -f ${WRKSRC}/scripts/tests/test_translation_fixer/test_markdown_links/test_mkd_links_number_mismatch.py
	${RM} -f ${WRKSRC}/tests/test_tutorial/test_graphql/test_tutorial001.py
# sqlmodel
	${RM} -f ${WRKSRC}/tests/test_tutorial/test_sql_databases/test_tutorial001.py
	${RM} -f ${WRKSRC}/tests/test_tutorial/test_sql_databases/test_tutorial002.py
# a2wsgi
	${RM} -f ${WRKSRC}/tests/test_tutorial/test_wsgi/test_tutorial001.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
