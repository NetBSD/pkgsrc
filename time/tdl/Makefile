# $NetBSD: Makefile,v 1.4 2013/07/15 02:02:29 ryoon Exp $

DISTNAME=	tdl-1.5.2
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.rpcurnow.force9.co.uk/tdl/
COMMENT=	Todo list manager with tons of features

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
