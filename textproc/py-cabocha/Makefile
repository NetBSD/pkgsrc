# $NetBSD: Makefile,v 1.5 2014/01/25 10:30:23 wiz Exp $

.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	CaboCha python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.67

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
