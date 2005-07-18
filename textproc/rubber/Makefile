# $NetBSD: Makefile,v 1.6 2005/07/18 13:46:45 tonio Exp $
#

DISTNAME=		rubber-1.0
CATEGORIES=		textproc
MASTER_SITES=		http://ebeffara.free.fr/pub/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.pps.jussieu.fr/~beffara/soft/rubber/
COMMENT=		Automated system for building LaTeX documents

DEPENDS+=		teTeX-bin-[0-9]*:../../print/teTeX-bin

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=         gmake
USE_MAKEINFO=           yes
INFO_FILES=             rubber.info
TEXINFO_REQD=		4.6
PYTHON_VERSIONS_ACCEPTED=	24 23

CONFIGURE_ARGS=		--python=${PYTHONBIN} --prefix=${PREFIX} \
			--datadir=${PREFIX}/share

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
