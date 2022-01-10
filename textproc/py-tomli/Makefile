# $NetBSD: Makefile,v 1.5 2022/01/10 19:16:03 adam Exp $

# Important: Re-generate files/setup.py on update.
DISTNAME=	tomli-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/tomli
COMMENT=	Lil' TOML parser
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
