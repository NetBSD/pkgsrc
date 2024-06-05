# $NetBSD: Makefile,v 1.96 2024/06/05 22:44:58 wiz Exp $

PYTHON_27_ACCEPTED=	yes

PKGREVISION= 1
.include "../../textproc/libxml2/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Python wrapper for libxml2
LICENSE=	modified-bsd

USE_GCC_RUNTIME=	yes

PYSETUPSUBDIR=	python
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

# python/setup.py looks in various places for libxml2 and libiconv,
# including (usually incorrectly) in /usr/include, /usr/local/include
# and /opt/include, and finally (usually correctly) in
# $prefix/include.  This can result in finding an old system libxml2,
# which is problematic in general, but can result in enabling legacy
# functions e.g. xmlCleanupPredefinedEntities which will then fail at
# import time.
#
# The following attempts to patch around this, but it is not good
# enough with pkgsrc xml2 and native iconv because the iconv include
# path is first.  This can happen on old macOS.
#
# \todo Patch setup.py.in to have @LIBXML2_PREFIX@ and @ICONV_PREFIX@
# (in order) and then substite those, or at least ensure that the
# iconv prefix is afterwwards.
#
SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	python/setup.py
SUBST_NOOP_OK.setup=	yes # PREFIX may be /usr/local
SUBST_SED.setup=	-e "/ROOT/s,'/usr/local','${BUILDLINK_PREFIX.libxml2}',g"
SUBST_SED.setup+=	-e "/^\"/s,/usr/include,${BUILDLINK_PREFIX.iconv}/include,g"
SUBST_SED.setup+=	-e "/^\"/s,/usr/local/include,${BUILDLINK_PREFIX.iconv}/include,g"

BUILDLINK_TRANSFORM.Darwin+=	opt:-bundle:-dynamiclib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install: fix-darwin-install-name
.PHONY: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/libxml2mod.so \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/libxml2mod.so
.endif

EGG_NAME=	${DISTNAME:S/-/_python-/}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=${PKGVERSION_NOREV}
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
