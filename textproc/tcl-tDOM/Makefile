# $NetBSD: Makefile,v 1.6 2019/10/06 03:25:17 kamil Exp $
#

DISTNAME=	tdom-${VERSION}-src
PKGNAME=	tcl-tDOM-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://tdom.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://tdom.org/
COMMENT=	High performance XML data handling library for Tcl using Expat
LICENSE=	mpl-1.1 AND mit # builtin expat is mit

EXTRACT_USING=	bsdtar

VERSION=	0.9.1

USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/tdom-${VERSION}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
