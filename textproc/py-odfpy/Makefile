# $NetBSD: Makefile,v 1.2 2018/07/06 11:03:10 adam Exp $

DISTNAME=	odfpy-1.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/odfpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eea/odfpy
COMMENT=	Python API and tools to manipulate OpenDocument files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

post-install:
.for bin in csv2ods mailodf odf2mht odf2xhtml odf2xml odfimgimport \
	odflint odfmeta odfoutline odfuserfield xml2odf
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
