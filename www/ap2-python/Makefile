# $NetBSD: Makefile,v 1.43 2023/08/28 09:47:46 gdt Exp $

# Upstream tends to not have releases, so one must be cautious the
# tags section of their site, or repology.  However, they did make a
# release on request:
#   https://github.com/grisha/mod_python/issues/126
DISTNAME=	mod_python-3.5.0.1
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=grisha/}
GITHUB_PROJECT=	mod_python

# This release wrongly uses 3.5.0 as the egg name.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grisha/mod_python
#HOMEPAGE+=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter
LICENSE=	apache-2.0

# HACK: This is not needed, but if it's installed, the PLIST differs
# so just depend on it to make it consistently install the same files.
# \todo: With 3.5.0.1, this might no longer be necessary.
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

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
