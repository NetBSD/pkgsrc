# $NetBSD: Makefile,v 1.4 2014/01/25 10:30:25 wiz Exp $
#

.include "../../textproc/yamcha/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES+=	python

COMMENT=	YamCha python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.33

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../textproc/yamcha/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
