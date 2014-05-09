# $NetBSD: Makefile,v 1.28 2014/05/09 07:37:22 wiz Exp $

DISTNAME=	rubber-1.1
PKGREVISION=	5
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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
