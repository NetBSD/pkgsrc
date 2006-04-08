# $NetBSD: Makefile,v 1.21 2006/04/08 05:02:59 jlam Exp $
#

DISTNAME=	ratpoison-1.4.0-beta4
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	wm
MASTER_SITES=	http://savannah.nongnu.org/download/ratpoison/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/ratpoison/
COMMENT=	Simple window manager with no fat library dependencies

GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES
INFO_FILES=		# PLIST

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/usr/bin/env bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	contrib/rpws

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
