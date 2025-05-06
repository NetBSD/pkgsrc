# $NetBSD: Makefile,v 1.23 2025/05/06 12:07:36 wiz Exp $

DISTNAME=	pyenchant-3.2.2
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyenchant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyenchant.github.io/pyenchant/
COMMENT=	Spellchecking library for Python
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	enchant2-[0-9]*:../../textproc/enchant2

USE_LANGUAGES=	# none

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	pre-configure
SUBST_MESSAGE.libpath=	Fixing libenchant2 path.
SUBST_FILES.libpath=	enchant/_enchant.py
SUBST_SED.libpath=	-e 's,@PYENCHANT_LIBRARY_PATH@,${PREFIX}/lib/libenchant-2.${SHLIB_EXT},g'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
