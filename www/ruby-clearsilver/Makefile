# $NetBSD: Makefile,v 1.13 2008/10/06 01:04:29 minskim Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}

.include "../../www/clearsilver/Makefile.common"

RUBY_HAS_ARCHLIB=		yes
CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY:Q}

INSTALL_DIRS=			${WRKSRC}/ruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
