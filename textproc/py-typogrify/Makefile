# $NetBSD: Makefile,v 1.2 2022/06/28 11:36:49 wiz Exp $

DISTNAME=	typogrify-2.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typogrify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mintchaos/typogrify
COMMENT=	Filters to enhance web typography
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-smartypants-[0-9]*:../../textproc/py-smartypants
# tests don't run because of django setup errors, or warnings about the missing two module
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
# django.core.exceptions.ImproperlyConfigured: Requested settings, but settings are not configured. You must either define the environment variable DJANGO_SETTINGS_MODULE or call settings.configure() before accessing settings.
TEST_DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
