# $NetBSD: Makefile,v 1.3 2005/01/28 14:08:02 taca Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=			1

.include "../../www/clearsilver/Makefile.common"

DEPENDS+=			${CLEARSILVER_BASE}:../../www/clearsilver-base

RUBY_HAS_ARCHLIB=		yes
CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY}

INSTALL_DIRS=			${WRKSRC}/ruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
