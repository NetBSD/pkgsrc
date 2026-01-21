# $NetBSD: Makefile,v 1.10 2026/01/21 08:52:07 adam Exp $

DISTNAME=	dill-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uqfoundation/dill
COMMENT=	Serialize all of Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
.for file in get_gprof get_objgraph undill
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
