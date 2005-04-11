# $NetBSD: Makefile,v 1.15 2005/04/11 21:47:48 tv Exp $
#

DISTNAME=	ratpoison-1.3.0
CATEGORIES=	wm
MASTER_SITES=	http://savannah.nongnu.org/download/ratpoison/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/ratpoison/
COMMENT=	Simple window manager with no fat library dependencies

USE_X11=	YES
GNU_CONFIGURE=	YES
USE_GNU_READLINE= YES

INFO_FILES=	ratpoison.info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
