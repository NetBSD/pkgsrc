# $NetBSD: Makefile,v 1.27 2012/10/08 13:04:17 asau Exp $
#

DISTNAME=	etm-877
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.duke.edu/~dgraham/ETM/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.duke.edu/~dgraham/ETM/
COMMENT=	events and tasks manager using simple text files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.8.7:../../x11/py-wxWidgets
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-icalendar>=2.0.1:../../time/py-icalendar

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	etm/etmWX.py
REPLACE_PYTHON+=	etm/etmData.py

# Delete an unnecessary file
post-configure:
	${RM} ${WRKSRC}/etm.egg-info/.SOURCES.txt~

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
