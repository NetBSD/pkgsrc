# $NetBSD: Makefile,v 1.14 2005/03/19 15:24:31 wiz Exp $
#

DISTNAME=	ratpoison-1.3.0
CATEGORIES=	wm
MASTER_SITES=	http://savannah.nongnu.org/download/ratpoison/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/ratpoison/
COMMENT=	Simple window manager with no fat library dependencies

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
USE_GNU_READLINE= YES

INFO_FILES=	ratpoison.info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
