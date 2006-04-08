# $NetBSD: Makefile,v 1.14 2006/04/08 05:12:12 jlam Exp $
#

DISTNAME=		rubber-1.0
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		http://ebeffara.free.fr/pub/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.pps.jussieu.fr/~beffara/soft/rubber/
COMMENT=		Automated system for building LaTeX documents

USE_TOOLS+=		makeinfo
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
INFO_FILES=		# PLIST
TEXINFO_REQD=		4.6
PYTHON_VERSIONS_ACCEPTED=	24 23
TEX_ACCEPTED=		teTeX1 teTeX2 teTeX3

CONFIGURE_ARGS+=	--python=${PYTHONBIN:Q}				
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${PKGINFODIR:Q}

.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
