# $NetBSD: Makefile,v 1.3 2018/12/04 13:25:59 adam Exp $

DISTNAME=	odfpy-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/odfpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eea/odfpy
COMMENT=	Python API and tools to manipulate OpenDocument files
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml

USE_LANGUAGES=	# none

post-install:
.for bin in csv2ods mailodf odf2mht odf2xhtml odf2xml odfimgimport \
	odflint odfmeta odfoutline odfuserfield xml2odf
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
