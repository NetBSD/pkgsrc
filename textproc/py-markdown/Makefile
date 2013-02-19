# $NetBSD: Makefile,v 1.6 2013/02/19 19:41:28 ryoon Exp $

DISTNAME=	Markdown-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/M/Markdown/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/Markdown
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

PYDISTUTILSPKG=		yes
PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
