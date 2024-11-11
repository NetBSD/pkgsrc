# $NetBSD: Makefile,v 1.7 2024/11/11 07:29:02 wiz Exp $

DISTNAME=	dill-0.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uqfoundation/dill
COMMENT=	Serialize all of Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
.for file in get_gprof get_objgraph undill
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
