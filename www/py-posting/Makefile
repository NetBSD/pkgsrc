# $NetBSD: Makefile,v 1.2 2024/07/18 04:52:45 wiz Exp $

DISTNAME=	posting-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/posting/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/darrenburns/posting
COMMENT=	Modern API client that lives in your terminal
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-textual-[0-9]*:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-textual-autocomplete-[0-9]*:../../comms/py-textual-autocomplete
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-default-group-[0-9]*:../../devel/py-click-default-group
DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-pyperclip-[0-9]*:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-pydantic-[0-9]*:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-pydantic-settings-[0-9]*:../../devel/py-pydantic-settings
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dotenv-[0-9]*:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-xdg-base-dirs-[0-9]*:../../devel/py-xdg-base-dirs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39 310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} posting posting-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
