# $NetBSD: Makefile,v 1.1.1.1 2008/03/02 02:41:26 obache Exp $
#

.include "../../textproc/suikyo/Makefile.common"

PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/-/-elisp-/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/suikyo/elisp/index.html
COMMENT=	Suikyo for Emacs Lisp

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	suikyo-conv-table>=${SUIKYO_VER}:../../textproc/suikyo-conv-table
DEPENDS+=	suikyo-docs>=${SUIKYO_VER}:../../textproc/suikyo-docs

BUILD_DIRS+=	elisp

CONFIGURE_ARGS+=	--with-emacs-sitelispdir=${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
