# $NetBSD: Makefile,v 1.7 2019/04/26 13:14:17 maya Exp $
#

.include "../../textproc/marisa/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	MARISA python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	bindings/python
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.2.4

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	bindings/python/setup.py
SUBST_SED.version=	-e s,@VERSION@,${PKGVERSION_NOREV},

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../textproc/marisa/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
