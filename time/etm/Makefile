# $NetBSD: Makefile,v 1.31 2014/05/09 07:37:22 wiz Exp $

DISTNAME=	etm-877
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.duke.edu/~dgraham/ETM/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.duke.edu/~dgraham/ETM/
COMMENT=	Events and tasks manager using simple text files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.8.7:../../x11/py-wxWidgets
DEPENDS+=	${PYPKGPREFIX}-icalendar>=2.0.1:../../time/py-icalendar

PYTHON_VERSIONED_DEPENDENCIES=	dateutil
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-wxWidgets

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	etm/etmWX.py
REPLACE_PYTHON+=	etm/etmData.py

# Delete an unnecessary file
post-configure:
	${RM} ${WRKSRC}/etm.egg-info/.SOURCES.txt~

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
