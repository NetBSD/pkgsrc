# $NetBSD: Makefile,v 1.3 2003/01/19 10:59:00 salo Exp $
#

DISTNAME=	lablgtk-1.2.5
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ bindings for ocaml

USE_BUILDLINK2=	YES
USE_GMAKE=	YES

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		configure USE_DOTOPT=1 USE_CC=1 CC=${CC}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		opt

.include "../../x11/gtk/buildlink2.mk"
.include "../../lang/ocaml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
