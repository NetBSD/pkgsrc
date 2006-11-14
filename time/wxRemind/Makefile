# $NetBSD: Makefile,v 1.2 2006/11/14 13:38:16 joerg Exp $
#

DISTNAME=		wxRemind-0.6.18
CATEGORIES=		time
MASTER_SITES=		http://www.duke.edu/~dgraham/wxRemind/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.duke.edu/~dgraham/wxRemind/
COMMENT=		Graphical front-end to Remind

DEPENDS+=		${PYPKGPREFIX}-wxWidgets>=2.6.1:../../x11/py-wxWidgets
DEPENDS+=		${PYPKGPREFIX}-setuptools>=0.6b1:../../devel/py-setuptools

PYTHON_VERSIONS_ACCEPTED=	24
PYDISTUTILSPKG=			YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
