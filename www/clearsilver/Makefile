# $NetBSD: Makefile,v 1.2 2004/02/27 01:46:59 epg Exp $

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
PYTHON_PATCH_SCRIPTS=	scripts/document.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
