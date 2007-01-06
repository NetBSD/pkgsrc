# $NetBSD: Makefile,v 1.23 2007/01/06 18:44:46 rillig Exp $
#

DISTNAME=	ratpoison-1.4.1
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	wm
MASTER_SITES=	http://savannah.nongnu.org/download/ratpoison/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/ratpoison/
COMMENT=	Simple window manager with no fat library dependencies

GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES
INFO_FILES=		yes

USE_TOOLS+=	perl:run
REPLACE_PERL+=	contrib/rpws contrib/clickframe.pl

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
