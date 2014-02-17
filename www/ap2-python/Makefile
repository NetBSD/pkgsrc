# $NetBSD: Makefile,v 1.31 2014/02/17 17:20:28 adam Exp $

DISTNAME=	mod_python-3.5.0
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www python
MASTER_SITES=	http://archive.apache.org/dist/httpd/modpython/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter
LICENSE=	apache-2.0

PKG_APACHE_ACCEPTED=	apache2 apache22 apache24

MAKE_JOBS_SAFE=		no

APACHE_MODULE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}

INSTALLATION_DIRS+=	bin
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
