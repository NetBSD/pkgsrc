# $NetBSD: Makefile,v 1.33 2014/06/10 15:22:17 joerg Exp $

DISTNAME=	mod_python-3.5.0
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www python
MASTER_SITES=	http://dist.modpython.org/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter
LICENSE=	apache-2.0

PKG_APACHE_ACCEPTED=	apache22 apache24

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
