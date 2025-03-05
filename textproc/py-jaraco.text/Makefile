# $NetBSD: Makefile,v 1.12 2025/03/05 10:32:05 wiz Exp $

DISTNAME=	jaraco_text-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.text
COMMENT=	Module for text manipulation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-autocommand-[0-9]*:../../misc/py-autocommand
DEPENDS+=	${PYPKGPREFIX}-jaraco.context>=4.1:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools-[0-9]*:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
# inflect
DEPENDS+=	${PYPKGPREFIX}-inflect-[0-9]*:../../lang/py-inflect

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
