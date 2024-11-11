# $NetBSD: Makefile,v 1.8 2024/11/11 07:29:29 wiz Exp $

DISTNAME=	wagtailnews-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wagtailnews/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neon-jungle/wagtailnews
COMMENT=	News system for the Wagtail CMS
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wagtail>=5.2.0:../../www/py-wagtail

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
