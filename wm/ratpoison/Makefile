# $NetBSD: Makefile,v 1.19 2006/03/09 14:50:31 ghen Exp $
#

DISTNAME=	ratpoison-1.4.0-beta4
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	wm
MASTER_SITES=	http://savannah.nongnu.org/download/ratpoison/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/ratpoison/
COMMENT=	Simple window manager with no fat library dependencies

GNU_CONFIGURE=	YES
USE_GNU_READLINE= YES

INFO_FILES=	ratpoison.info

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	/usr/bin/env bash
_REPLACE.bash.new=	${SH:Q}
_REPLACE_FILES.bash=	contrib/rpws

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
