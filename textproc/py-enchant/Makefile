# $NetBSD: Makefile,v 1.14 2017/06/01 13:30:26 jlam Exp $

DISTNAME=	pyenchant-1.6.6
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyenchant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/pyenchant/
COMMENT=	Spellchecking library for Python
LICENSE=	gnu-lgpl-v2.1

.include "../../lang/python/pyversion.mk"

DEPENDS+=	enchant-[0-9]*:../../textproc/enchant

USE_LANGUAGES=	# empty

.include "../../mk/bsd.prefs.mk"

DLEXT.dylib=	dylib
DLEXT=		${DLEXT.${SHLIB_TYPE}:Uso}
PYENCHANT_LIBRARY_PATH=	${LOCALBASE}/lib/libenchant.${DLEXT}

# fix the path of libenchant with patch-ab.
SUBST_CLASSES+=		dlpath
SUBST_STAGE.dlpath=	pre-configure
SUBST_FILES.dlpath=	enchant/_enchant.py
SUBST_VARS.dlpath=	PYENCHANT_LIBRARY_PATH

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
