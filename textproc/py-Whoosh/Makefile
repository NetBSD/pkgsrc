# $NetBSD: Makefile,v 1.13 2017/10/07 11:07:39 adam Exp $

DISTNAME=	Whoosh-2.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Whoosh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mchaput/whoosh/wiki/Home
COMMENT=	Fast, featureful full-text indexing and searching library implemented
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
