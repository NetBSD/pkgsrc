# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:17 wiz Exp $
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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
