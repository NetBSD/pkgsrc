# $NetBSD: Makefile,v 1.37 2015/01/11 21:20:21 wiz Exp $

DISTNAME=		html2text-2014.12.29
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		http://pypi.python.org/packages/source/h/html2text/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text
LICENSE=		gnu-gpl-v2

PYTHON_SELF_CONFLICT=	yes
PYDISTUTILSPKG=		yes
REPLACE_PYTHON=		html2text/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
