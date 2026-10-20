# $NetBSD: Makefile,v 1.1 2026/10/20 10:13:11 adam Exp $

DISTNAME=	feedparser_sgmllib-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedparser-sgmllib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-syndication/feedparser-sgmllib
COMMENT=	For feedparser: sgmllib from Python 2.7
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
