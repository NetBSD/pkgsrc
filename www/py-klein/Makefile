# $NetBSD: Makefile,v 1.1 2021/01/28 21:22:04 maya Exp $

DISTNAME=	klein-20.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/83/b4/3642700d37b513ef1574e18f89aa545a9dca8986ab5d137e743623e24797/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://klein.readthedocs.io/en/latest/
COMMENT=	Micro-framework for developing web services
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-incremental-[0-9]*:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-hyperlink-[0-9]*:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tubes-[0-9]*:../../devel/py-tubes
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
