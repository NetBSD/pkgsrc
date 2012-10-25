# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:51 asau Exp $

DISTNAME=	Markdown-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-markdown/} \
		http://pypi.python.org/packages/source/M/Markdown/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.freewisdom.org/projects/python-markdown/
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

PYDISTUTILSPKG=		yes
PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
