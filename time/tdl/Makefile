# $NetBSD: Makefile,v 1.3 2012/10/08 13:04:29 asau Exp $

DISTNAME=	tdl-1.5.2
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.rpcurnow.force9.co.uk/tdl/
COMMENT=	Todo list manager with tons of features

HAS_CONFIGURE=	YES
USE_GNU_READLINE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
