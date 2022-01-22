# $NetBSD: Makefile,v 1.2 2022/01/22 14:16:31 wiz Exp $

DISTNAME=	sip-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-sip5-5.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sip/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/sip/
COMMENT=	Tool to create Python bindings for C++ libraries (v5)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c c++

CLI=			build distinfo install module sdist wheel
MODULE.build=		sipbuild.tools.build
MODULE.distinfo=	sipbuild.distinfo.main
MODULE.install=		sipbuild.tools.install
MODULE.module=		sipbuild.module.main
MODULE.sdist=		sipbuild.tools.sdist
MODULE.wheel=		sipbuild.tools.wheel
MODULE.sip5=		sipbuild.legacy.sip5

# Overwrite the console scripts with versions that don't fail
# when sip-4.* is also installed.
post-install:
.for cli in ${CLI}
	{ ${ECHO} "#!${PYTHONBIN}"; \
	  ${ECHO} "import sys"; \
	  ${ECHO} "from ${MODULE.${cli}} import main; sys.exit(main());"; \
	} > ${DESTDIR}${PREFIX}/bin/sip-${cli}
.endfor
	{ ${ECHO} "#!${PYTHONBIN}"; \
	  ${ECHO} "import sys"; \
	  ${ECHO} "from ${MODULE.sip5} import main; sys.exit(main());"; \
	} > ${DESTDIR}${PREFIX}/bin/sip5

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
