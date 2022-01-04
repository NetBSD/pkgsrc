# $NetBSD: Makefile,v 1.18 2022/01/04 20:54:54 wiz Exp $

DISTNAME=	pyenchant-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyenchant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/pyenchant/
COMMENT=	Spellchecking library for Python
LICENSE=	gnu-lgpl-v2.1

.include "../../lang/python/pyversion.mk"

DEPENDS+=	enchant2-[0-9]*:../../textproc/enchant2

USE_LANGUAGES=	# empty

.include "../../mk/bsd.prefs.mk"

DLEXT.dylib=		dylib
DLEXT=			${DLEXT.${SHLIB_TYPE}:Uso}
PYENCHANT_LIBRARY_PATH=	${PREFIX}/lib/libenchant-2.${DLEXT}

# fix the path of libenchant with patch-ab.
SUBST_CLASSES+=		dlpath
SUBST_STAGE.dlpath=	pre-configure
SUBST_FILES.dlpath=	enchant/_enchant.py
SUBST_VARS.dlpath=	PYENCHANT_LIBRARY_PATH

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
