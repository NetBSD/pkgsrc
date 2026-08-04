# $NetBSD: Makefile,v 1.8 2026/08/04 20:29:18 wiz Exp $

DISTNAME=	tdl-1.5.2
PKGREVISION=	1
CATEGORIES=	time
#MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.rpcurnow.force9.co.uk/tdl/
COMMENT=	Todo list manager with tons of features

HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
