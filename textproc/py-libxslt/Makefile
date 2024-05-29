# $NetBSD: Makefile,v 1.71 2024/05/29 16:34:39 adam Exp $

PKGREVISION= 1
.include "../../textproc/libxslt/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Python wrapper for libxslt

DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.6.8:../../textproc/py-libxml2

EGG_NAME=	libxslt_python-${PKGVERSION_NOREV}

PYSETUPSUBDIR=	python
NO_CONFIGURE=	yes

MAKE_ENV+=	PYLIBXSLTVERSION=${PKGVERSION_NOREV}

PYSITEDIR=	${PREFIX}/lib/python${PYVERSSUFFIX}/site-packages

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	python/setup.py
SUBST_SED.setup=	-e "s,@LIBICONVDIR@,${BUILDLINK_PREFIX.iconv},g"
SUBST_SED.setup+=	-e "s,@LIBXML2DIR@,${BUILDLINK_PREFIX.libxml2},g"
SUBST_SED.setup+=	-e "s,@LIBXSLTDIR@,${BUILDLINK_PREFIX.libxslt},g"
SUBST_SED.setup+=	-e "s,@PYSHLIBDIR@,${PYSITEDIR},g"

post-extract: setuppy
.PHONY: setuppy
setuppy:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/python

.include "../../lang/python/batteries-included.mk"
# this must come before py-libxml2's bl3 or the direct dependence is lost
.include "../../lang/python/pyversion.mk"

.include "../../textproc/py-libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=${PKGVERSION_NOREV}
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
