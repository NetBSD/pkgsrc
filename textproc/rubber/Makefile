# $NetBSD: Makefile,v 1.22 2010/03/12 10:30:04 tonio Exp $
#

DISTNAME=		rubber-1.1
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		http://ebeffara.free.fr/pub/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.pps.jussieu.fr/~beffara/soft/rubber/
COMMENT=		Automated system for building LaTeX documents

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
INFO_FILES=		yes
TEXINFO_REQD=		4.6
TEX_ACCEPTED=		teTeX3

CONFIGURE_ARGS+=	--python=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${PKGINFODIR:Q}

PLIST_SUBST+=		RUBBERVERSUFFIX=${PKGVERSION_NOREV}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
