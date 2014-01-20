# $NetBSD: Makefile,v 1.4 2014/01/20 19:20:08 joerg Exp $
#

DISTNAME=	tDOM-0.8.3
PKGNAME=	tcl-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://cloud.github.com/downloads/tDOM/tdom/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://tdom.github.com/
COMMENT=	High performance XML data handling library for Tcl using Expat
LICENSE=	mpl-1.1

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

CPPFLAGS+=	-DUSE_INTERP_ERRORLINE

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
