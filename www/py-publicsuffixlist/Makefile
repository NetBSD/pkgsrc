# $NetBSD: Makefile,v 1.24 2025/11/11 13:44:47 adam Exp $

DISTNAME=	publicsuffixlist-1.0.2.20251109
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/publicsuffixlist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ko-zu/psl
COMMENT=	Public Suffix List parser implementation
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# update
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} publicsuffixlist-download publicsuffixlist-download-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
