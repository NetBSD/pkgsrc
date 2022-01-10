# $NetBSD: Makefile,v 1.20 2022/01/10 21:51:09 wiz Exp $

DISTNAME=	PyX-0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyx-project.org/
COMMENT=	Package for the creation of PostScript, PDF, and SVG files
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

USE_LANGUAGES=	# none

CONF_FILES=	${PYSITELIB}/pyx/data/pyxrc \
		${PKG_SYSCONFDIR}/pyxrc

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
