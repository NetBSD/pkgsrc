# $NetBSD: Makefile,v 1.5 2005/10/16 15:14:27 taca Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=			2

.include "../../www/clearsilver/Makefile.common"

DEPENDS+=			${CLEARSILVER_BASE}:../../www/clearsilver-base

USE_RUBY_DIST_SUBDIR=		no
RUBY_HAS_ARCHLIB=		yes
CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY}

INSTALL_DIRS=			${WRKSRC}/ruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
