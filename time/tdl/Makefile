# $NetBSD: Makefile,v 1.1.1.1 2008/09/04 11:13:29 tonnerre Exp $

DISTNAME=	tdl-1.5.2
CATEGORIES=	time
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/tdl/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.rpcurnow.force9.co.uk/tdl/
COMMENT=	Todo list manager with tons of features

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
USE_GNU_READLINE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
