# $NetBSD: Makefile,v 1.27 2014/05/09 07:37:23 wiz Exp $

DISTNAME=		mod_python-2.7.11
PKGNAME=		ap13-${PYPKGPREFIX}-python-2.7.11
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.modpython.org/
COMMENT=		Python interpreter embedded into Apache

USE_TOOLS+=	pax

CONFLICTS=	ap-python-[0-9]* ap13-python-[0-9]* ap13-py[0-9]*-python-[0-9]*
SUPERSEDES=	ap13-python-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON_BIN=${PYTHONBIN:Q} ac_cv_path_MKDEP=

INSTALLATION_DIRS=	lib/httpd share/doc/ap-mod_python

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.7.11; 3.5.0 is supposed to work

post-install:
	cd ${WRKSRC}/doc-html && pax -rwpe . ${DESTDIR}${PREFIX}/share/doc/ap-mod_python

.include "../../lang/python/extension.mk"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
