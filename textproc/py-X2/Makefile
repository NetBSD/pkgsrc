# $NetBSD: Makefile,v 1.2 2014/05/09 07:37:21 wiz Exp $

DISTNAME=	PyX-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyx.sourceforge.net/
COMMENT=	Package for the creation of PostScript and PDF files
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

USE_LANGUAGES=	#none

CONF_FILES=	${PYSITELIB}/pyx/data/pyxrc \
		${PKG_SYSCONFDIR}/pyxrc

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=33 34

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
