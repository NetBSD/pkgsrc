# $NetBSD: Makefile,v 1.14 2018/11/12 12:25:51 kleink Exp $

DISTNAME=	WTForms-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://wtforms.readthedocs.io/
COMMENT=	Flexible forms validation and rendering library
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-babel>=2.6.0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-email_validator-[0-9]*:../../mail/py-email_validator
.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
.endif
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
