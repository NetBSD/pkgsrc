# $NetBSD: Makefile,v 1.1 2020/04/06 08:03:00 wiz Exp $

DISTNAME=	sphobjinv-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphobjinv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bskinn/sphobjinv
COMMENT=	Toolkit for manipulation and inspection of Sphinx objects.inv files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-fuzzywuzzy>=0.3:../../devel/py-fuzzywuzzy
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.0:../../textproc/py-jsonschema

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} sphobjinv sphobjinv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
