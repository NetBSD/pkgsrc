# $NetBSD: Makefile,v 1.19 2008/04/25 20:39:13 joerg Exp $
#

DISTNAME=		rubber-1.1
PKGREVISION=		1
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
TEX_ACCEPTED=		teTeX3

CONFIGURE_ARGS+=	--python=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${PKGINFODIR:Q}

.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
