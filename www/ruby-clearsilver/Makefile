# $NetBSD: Makefile,v 1.6 2005/10/29 19:29:52 epg Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}

.include "../../www/clearsilver/Makefile.common"

USE_RUBY_DIST_SUBDIR=		no
RUBY_HAS_ARCHLIB=		yes
CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY}

INSTALL_DIRS=			${WRKSRC}/ruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
