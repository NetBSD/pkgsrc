# $NetBSD: Makefile,v 1.1 2012/08/26 12:12:28 wiz Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
