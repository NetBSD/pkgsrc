# $NetBSD: Makefile,v 1.10 2022/01/10 22:15:36 wiz Exp $

PKGREVISION= 1
.include "../../textproc/marisa/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	MARISA python module

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	bindings/python
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.2.4

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	bindings/python/setup.py
SUBST_SED.version=	-e s,@VERSION@,${PKGVERSION_NOREV},

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../textproc/marisa/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
