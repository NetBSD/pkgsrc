# $NetBSD: Makefile,v 1.7 2005/10/17 17:12:04 tonio Exp $
#

DISTNAME=		rubber-1.0
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://ebeffara.free.fr/pub/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.pps.jussieu.fr/~beffara/soft/rubber/
COMMENT=		Automated system for building LaTeX documents

DEPENDS+=		teTeX-bin-[0-9]*:../../print/teTeX-bin

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_MAKEINFO=		yes
INFO_FILES=		rubber.info
TEXINFO_REQD=		4.6
PYTHON_VERSIONS_ACCEPTED=	24 23

CONFIGURE_ARGS=		--python=${PYTHONBIN} --prefix=${PREFIX} \
			--datadir=${PREFIX}/share

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
