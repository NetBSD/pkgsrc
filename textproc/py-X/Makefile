# $NetBSD: Makefile,v 1.21 2026/01/12 12:31:49 adam Exp $

DISTNAME=	pyx-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyx/X/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyx-project.org/
COMMENT=	Package for the creation of PostScript, PDF, and SVG files
LICENSE=	gnu-gpl-v2 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

USE_LANGUAGES=	# none

CONF_FILES=	${PYSITELIB}/pyx/data/pyxrc \
		${PKG_SYSCONFDIR}/pyxrc

PYTHON_SELF_CONFLICT=		yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
