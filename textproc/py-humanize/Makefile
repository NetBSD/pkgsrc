# $NetBSD: Makefile,v 1.1 2017/04/04 11:34:05 wiz Exp $

DISTNAME=		humanize-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		python textproc
MASTER_SITES=		${MASTER_SITE_PYPI:=h/humanize/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://travis-ci.org/jmoiron/humanize
COMMENT=		Convert numbers into easily readable format
LICENSE=		mit

# TEST_DEPENDS
#BUILD_DEPENDS+=		${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
#BUILD_DEPENDS+=		${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
# tests not included in distfile

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
