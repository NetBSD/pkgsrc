# $NetBSD: Makefile,v 1.9 2005/11/08 20:02:52 tonio Exp $
#

DISTNAME=		rubber-1.0
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://ebeffara.free.fr/pub/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.pps.jussieu.fr/~beffara/soft/rubber/
COMMENT=		Automated system for building LaTeX documents

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_MAKEINFO=		yes
INFO_FILES=		rubber.info
TEXINFO_REQD=		4.6
PYTHON_VERSIONS_ACCEPTED=	24 23
LATEX_ACCEPTED=		teTeX1 teTeX2 teTeX3

CONFIGURE_ARGS+=	--python=${PYTHONBIN} --prefix=${PREFIX} \
			--datadir=${PREFIX}/share

.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
