# $NetBSD: Makefile,v 1.3 2012/10/25 06:56:48 asau Exp $
#

.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES+=	python

COMMENT=	CaboCha python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
