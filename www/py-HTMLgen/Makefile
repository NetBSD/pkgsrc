# $NetBSD: Makefile,v 1.23 2023/12/23 20:38:53 zafer Exp $

DISTNAME=	HTMLgen
PKGNAME=	${PYPKGPREFIX}-HTMLgen-2.2.2
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	#
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	py-HTMLgen-2.2.2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://starship.python.net/crew/friedrich/HTMLgen/html/main.html
COMMENT=	Class library for the generation of HTML documents

NO_BUILD=	yes
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}
PY_PATCHPLIST=	yes

REPLACE_PYTHON+=	*.py

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS+=	${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
