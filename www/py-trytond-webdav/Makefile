# $NetBSD: Makefile,v 1.7 2019/04/26 13:14:22 maya Exp $
TRYTON_MODULE_NAME=	trytond_webdav
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Webdav module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pywebdav-[0-9]*:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

PYTHON_VERSIONS_INCOMPATIBLE=    36 37

REPLACE_PYTHON+=	tests/test_webdav.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/trytond-webdav \
		${DESTDIR}${PREFIX}/bin/trytond-webdav${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
