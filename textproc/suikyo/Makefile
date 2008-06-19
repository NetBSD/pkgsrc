# $NetBSD: Makefile,v 1.2 2008/06/19 15:01:17 taca Exp $
#

.include "Makefile.common"

MAINTAINER=	obache@NetBSD.org
COMMENT=	Romaji-Kana conversion library

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	suikyo-conv-table>=${SUIKYO_VER}:../../textproc/suikyo-conv-table
DEPENDS+=	suikyo-docs>=${SUIKYO_VER}:../../textproc/suikyo-docs
DEPENDS+=	${EMACS_PKGNAME_PREFIX}suikyo-elisp>=${SUIKYO_VER}:../../textproc/suikyo-elisp
DEPENDS+=	${RUBY_PKGPREFIX}-suikyo>=${SUIKYO_VER}:../../textproc/ruby-suikyo

PKGCONFIG_OVERRIDE+=	suikyo.pc.in

CONFIGURE_ARGS+=	--with-emacs-sitelispdir=${EMACS_LISPPREFIX}
CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}

INSTALL_TARGET=		install-pkgconfigDATA

.include "../../mk/emacs.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
