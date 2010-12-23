# $NetBSD: Makefile,v 1.6 2010/12/23 00:26:09 wiz Exp $
#

DISTNAME=	pyenchant-1.6.5
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyenchant/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rfk.id.au/software/pyenchant/
COMMENT=	Spellchecking library for Python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/pyversion.mk"

.if ${PYPACKAGE} && ${PYPACKAGE} == "python24"
DEPENDS+=	${PYPKGPREFIX}-ctypes-[0-9]*:../../devel/py-ctypes
.endif
DEPENDS+=	enchant-[0-9]*:../../textproc/enchant

USE_LANGUAGES=	# empty

FIND_PREFIX:=	ENCHANT_DIR=enchant
.include "../../mk/find-prefix.mk"

.include "../../mk/bsd.prefs.mk"

DLEXT.dylib=	dylib
DLEXT=		${DLEXT.${_OPSYS_SHLIB_TYPE}:Uso}
PYENCHANT_LIBRARY_PATH=	${ENCHANT_DIR}/lib/libenchant.${DLEXT}

# fix the path of libenchant with patch-ab.
SUBST_CLASSES+=		dlpath
SUBST_STAGE.dlpath=	pre-configure
SUBST_FILES.dlpath=	enchant/_enchant.py
SUBST_VARS.dlpath=	PYENCHANT_LIBRARY_PATH

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
