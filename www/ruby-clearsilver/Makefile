# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:28 joerg Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=			3

.include "../../www/clearsilver/Makefile.common"

RUBY_HAS_ARCHLIB=		yes
CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY:Q}

INSTALL_DIRS=			${WRKSRC}/ruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
