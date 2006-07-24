# $NetBSD: Makefile,v 1.1.1.1 2006/07/24 23:04:09 wiz Exp $
#

DISTNAME=		wxRemind-0.6.18
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets
DEPENDS+=		py24-setuptools>=0.6b1:../../devel/py24-setuptools

PYTHON_VERSIONS_ACCEPTED=	24
PYDISTUTILSPKG=			YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
