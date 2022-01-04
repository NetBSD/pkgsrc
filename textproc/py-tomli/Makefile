# $NetBSD: Makefile,v 1.3 2022/01/04 20:55:08 wiz Exp $

DISTNAME=	tomli-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/tomli
COMMENT=	Lil' TOML parser
LICENSE=	mit

# it is possible to install this using flit_core, see
# https://github.com/takluyver/flit/pull/441/files
# for details. For now we keep using setuptools.

SUBST_CLASSES+=		version
SUBST_FILES.version+=	setup.py
SUBST_VARS.version+=	PKGVERSION_NOREV
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Setting version.

post-extract:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
