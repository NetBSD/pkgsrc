# $NetBSD: Makefile,v 1.6 2004/04/27 05:44:23 snj Exp $

DISTNAME=	clearsilver-0.9.7
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.clearsilver.net/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.clearsilver.net/
COMMENT=	Fast, powerful HTML template system

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

# All these really ought to be supported as separate packages...
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
CONFIGURE_ARGS+=	--disable-apache --disable-perl --disable-ruby
CONFIGURE_ARGS+=	--disable-java --disable-csharp

PY_PATCHPLIST=	YES
PYBINMODULE=	YES
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth
PYTHON_PATCH_SCRIPTS=	scripts/document.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
