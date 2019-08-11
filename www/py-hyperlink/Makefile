# $NetBSD: Makefile,v 1.7 2019/08/11 13:25:07 wiz Exp $

DISTNAME=	hyperlink-19.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperlink/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/hyperlink
COMMENT=	Featureful, correct URL for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
