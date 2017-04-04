# $NetBSD: Makefile,v 1.1 2017/04/04 11:26:54 wiz Exp $

DISTNAME=		tabulate-0.7.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_PYPI:=t/tabulate/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/tabulate
COMMENT=		Pretty-print tabular data
LICENSE=		mit

# TEST_DEPENDS
BUILD_DEPENDS+=		${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

# tests broken due to missing file in distribution as of 0.7.7
# https://bitbucket.org/astanin/python-tabulate/issues/110/test-commonpy-missing-in-pypi-tarball

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
