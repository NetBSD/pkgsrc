# $NetBSD: Makefile,v 1.3 2005/04/03 20:39:56 wiz Exp $
#

DISTNAME=		rubber-0.99.8
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://ebeffara.free.fr/pub/

MAINTAINER=		reilles@loria.fr
HOMEPAGE=		http://rubber.sourceforge.net/
COMMENT=		Automated system for building LaTeX documents

DEPENDS+=		teTeX-bin-[0-9]*:../../print/teTeX-bin

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GNU_TOOLS+=         make
USE_MAKEINFO=           yes
INFO_FILES=             rubber.info
TEXINFO_REQD=		4.6
PYTHON_VERSIONS_ACCEPTED=	23

CONFIGURE_ARGS=		--python=${PYTHONBIN} --prefix=${PREFIX} \
			--datadir=${PREFIX}/share

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
