# $NetBSD: Makefile,v 1.2 2012/10/25 06:57:03 asau Exp $
#

DISTNAME=	tDOM-0.8.3
PKGNAME=	tcl-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://cloud.github.com/downloads/tDOM/tdom/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://tdom.github.com/
COMMENT=	High performance XML data handling library for Tcl using Expat
LICENSE=	mpl-1.1

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
