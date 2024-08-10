# $NetBSD: Makefile,v 1.9 2024/08/10 08:10:03 wiz Exp $

DISTNAME=	odfpy-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/odfpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eea/odfpy
COMMENT=	Python API and tools to manipulate OpenDocument files
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml

# as of 1.4.1
# 115 passed, 1 skipped

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	setup.py
SUBST_VARS.man=		PKGMANDIR

post-extract:
	chmod -R g-w ${WRKSRC}

post-install:
.for bin in csv2ods mailodf odf2mht odf2xhtml odf2xml odfimgimport \
	odflint odfmeta odfoutline odfuserfield xml2odf
	${MV} ${DESTDIR}${PREFIX}/bin/${bin} \
	      ${DESTDIR}${PREFIX}/bin/${bin}-${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${bin}.1 \
	      ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${bin}-${PYVERSSUFFIX}.1
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
