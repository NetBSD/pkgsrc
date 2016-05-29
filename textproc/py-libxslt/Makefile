# $NetBSD: Makefile,v 1.46 2016/05/29 21:07:59 wiz Exp $

.include "../../textproc/libxslt/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Python wrapper for libxslt

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.6.8:../../textproc/py-libxml2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 1.1.28

PYSETUPSUBDIR=	python
NO_CONFIGURE=	yes

MAKE_ENV+=		PYLIBXSLTVERSION=${PKGVERSION}

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	python/setup.py
SUBST_SED.setup=	-e "s,@LIBICONVDIR@,${BUILDLINK_PREFIX.iconv},g"
SUBST_SED.setup+=	-e "s,@LIBXML2DIR@,${BUILDLINK_PREFIX.libxml2},g"
SUBST_SED.setup+=	-e "s,@LIBXSLTDIR@,${BUILDLINK_PREFIX.libxslt},g"

post-extract: setuppy
.PHONY: setuppy
setuppy:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/python

BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=${PKGVERSION}
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/distutils.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
