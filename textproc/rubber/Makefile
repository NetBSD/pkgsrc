# $NetBSD: Makefile,v 1.39 2023/08/14 05:25:24 wiz Exp $

DISTNAME=	rubber-1.1
PKGREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	http://ebeffara.free.fr/pub/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://launchpad.net/rubber
COMMENT=	Automated system for building LaTeX documents

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_TOOLS+=		makeinfo
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
INFO_FILES=		yes
TEXINFO_REQD=		4.6

CONFIGURE_ARGS+=	--python=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${PKGINFODIR:Q}

PLIST_SUBST+=		RUBBERVERSUFFIX=${PKGVERSION_NOREV}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
