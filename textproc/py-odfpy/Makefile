# $NetBSD: Makefile,v 1.6 2022/01/04 20:55:00 wiz Exp $

DISTNAME=	odfpy-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/odfpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eea/odfpy
COMMENT=	Python API and tools to manipulate OpenDocument files
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	setup.py
SUBST_VARS.man=		PKGMANDIR


post-install:
.for bin in csv2ods mailodf odf2mht odf2xhtml odf2xml odfimgimport \
	odflint odfmeta odfoutline odfuserfield xml2odf
	${MV} ${DESTDIR}${PREFIX}/bin/${bin} \
	      ${DESTDIR}${PREFIX}/bin/${bin}-${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${bin}.1 \
	      ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${bin}-${PYVERSSUFFIX}.1
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
