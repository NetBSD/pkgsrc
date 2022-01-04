# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:37 wiz Exp $

DISTNAME=	wagtailnews-2.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=neon-jungle/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/neon-jungle/wagtailnews
COMMENT=	News system for the Wagtail CMS
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	wagtailnews
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-wagtail>=2.9:../../www/py-wagtail

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-wagtail

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
