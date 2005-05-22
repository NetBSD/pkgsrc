# $NetBSD: Makefile,v 1.5 2005/05/22 20:08:35 jlam Exp $
#

DISTNAME=		rubber-0.99.8
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://ebeffara.free.fr/pub/

MAINTAINER=		reilles@loria.fr
HOMEPAGE=		http://rubber.sourceforge.net/
COMMENT=		Automated system for building LaTeX documents

DEPENDS+=		teTeX-bin-[0-9]*:../../print/teTeX-bin

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=         gmake
USE_MAKEINFO=           yes
INFO_FILES=             rubber.info
TEXINFO_REQD=		4.6
PYTHON_VERSIONS_ACCEPTED=	23

CONFIGURE_ARGS=		--python=${PYTHONBIN} --prefix=${PREFIX} \
			--datadir=${PREFIX}/share

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
