# $NetBSD: Makefile,v 1.39 2022/06/30 11:18:57 nia Exp $

DISTNAME=	mod_python-3.5.0
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-${DISTNAME:S/mod_//}
PKGREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	http://dist.modpython.org/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter
LICENSE=	apache-2.0

MAKE_JOBS_SAFE=		no

APACHE_MODULE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}
CONFIGURE_ARGS.apache=	# none (since --with-apxs2 is unknown)

SUBST_CLASSES+=			optimization
SUBST_STAGE.optimization=	pre-configure
SUBST_MESSAGE.optimization=	Adjust optimization
SUBST_FILES.optimization=	dist/Makefile.in
SUBST_SED.optimization=		-e 's,--optimize 2,--optimize 1,g'

INSTALLATION_DIRS+=	bin
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
