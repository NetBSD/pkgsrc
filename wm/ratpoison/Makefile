# $NetBSD: Makefile,v 1.26 2008/04/10 18:04:51 tonio Exp $
#

DISTNAME=	ratpoison-1.4.3
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
REPLACE_SH=	contrib/allwindows.sh

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
