# $NetBSD: Makefile,v 1.1 2016/03/08 19:51:25 bsiegert Exp $

DISTNAME=	python-docx-0.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-docx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openxml/python-docx
COMMENT=	Python library for Microsoft Word (.docx) files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml>=3.1.0:../../textproc/py-lxml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
