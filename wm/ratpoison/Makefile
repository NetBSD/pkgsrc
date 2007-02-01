# $NetBSD: Makefile,v 1.24 2007/02/01 17:26:39 joerg Exp $
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

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
