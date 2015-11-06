# $NetBSD: Makefile,v 1.1 2015/11/06 10:46:25 wiz Exp $

DISTNAME=	PyJWT-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyJWT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/jpadilla/pyjwt
COMMENT=	JSON Web Token implementation in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
