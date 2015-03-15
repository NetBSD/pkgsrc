# $NetBSD: Makefile,v 1.6 2015/03/15 16:47:19 hiramatsu Exp $
#

.include "Makefile.common"

PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Romaji-Kana conversion library

DEPENDS+=	suikyo-conv-table>=${SUIKYO_VER}:../../textproc/suikyo-conv-table
DEPENDS+=	suikyo-docs>=${SUIKYO_VER}:../../textproc/suikyo-docs
DEPENDS+=	${EMACS_PKGNAME_PREFIX}suikyo-elisp>=${SUIKYO_VER}:../../textproc/suikyo-elisp
DEPENDS+=	${RUBY_PKGPREFIX}-suikyo>=${SUIKYO_VER}:../../textproc/ruby-suikyo

PKGCONFIG_OVERRIDE+=	suikyo.pc.in

CONFIGURE_ARGS+=	--with-emacs-sitelispdir=${EMACS_LISPPREFIX}
CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}

INSTALL_TARGET=		install-pkgconfigDATA

.include "../../editors/emacs/modules.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
