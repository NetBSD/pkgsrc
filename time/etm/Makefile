# $NetBSD: Makefile,v 1.20 2010/06/15 13:22:59 wiz Exp $
#

DISTNAME=	etm-622
CATEGORIES=	time
MASTER_SITES=	http://www.duke.edu/~dgraham/ETM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.duke.edu/~dgraham/ETM/
COMMENT=	Event and Task Manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-icalendar-[0-9]*:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-wxWidgets-[0-9]*:../../x11/py-wxWidgets

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

SUBST_CLASSES+=		python
SUBST_SED.python+=	-e 's,\(\#! *\)python,\1${PYTHONBIN},'
SUBST_FILES.python=	ez_setup.py
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Replacing python interpreter.

REPLACE_PYTHON=		e.py etm/etmBusyFree.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
