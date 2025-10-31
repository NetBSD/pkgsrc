# $NetBSD: Makefile,v 1.9 2025/10/31 11:48:44 adam Exp $

DISTNAME=	patiencediff-0.2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/patiencediff/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/patiencediff
COMMENT=	Python implementation of the patiencediff algorithm
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.5.0:../../devel/py-setuptools-rust

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} patiencediff patiencediff-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
