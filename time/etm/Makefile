# $NetBSD: Makefile,v 1.12 2009/06/06 21:56:14 wiz Exp $
#

DISTNAME=	etm-286
CATEGORIES=	time
MASTER_SITES=	http://www.duke.edu/~dgraham/ETM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.duke.edu/~dgraham/ETM/
COMMENT=	Event and Task Manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-icalendar-[0-9]*:../../time/py-icalendar

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

SUBST_CLASSES+=		python
SUBST_SED.python+=	-e 's,\(\#! *\)python,\1${PYTHONBIN},'
SUBST_FILES.python=	ez_setup.py
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Replacing python interpreter.

REPLACE_PYTHON=		e.py ew.py etm/freetime.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
