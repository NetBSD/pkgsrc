# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 05:50:23 epg Exp $

DISTNAME=	clearsilver-0.9.7
CATEGORIES=	www
MASTER_SITES=	http://www.clearsilver.net/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.clearsilver.net/
COMMENT=	Fast, powerful HTML template system

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

PY_PATCHPLIST=	YES
PYBINMODULE=	YES

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
