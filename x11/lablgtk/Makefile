# $NetBSD: Makefile,v 1.1.1.1 2002/10/16 16:40:24 dillo Exp $
#

DISTNAME=	lablgtk-1.2.5
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ bindings for ocaml

USE_BUILDLINK2=	YES
USE_GMAKE=	YES

MAKE_ENV+=	INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		configure USE_DOTOPT=1 USE_CC=1 CC=${CC}

.include "../../x11/gtk/buildlink2.mk"
.include "../../lang/ocaml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
