# $NetBSD: Makefile,v 1.6 2017/04/19 11:24:39 jperkin Exp $

DISTNAME=	tdl-1.5.2
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rpcurnow.force9.co.uk/tdl/
COMMENT=	Todo list manager with tons of features

HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
