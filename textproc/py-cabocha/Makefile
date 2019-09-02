# $NetBSD: Makefile,v 1.13 2019/09/02 13:20:12 adam Exp $

.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	CaboCha python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.67

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
