# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 00:02:26 epg Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}

.include "../../www/clearsilver/Makefile.common"

DEPENDS+=			${CLEARSILVER_BASE}:../../www/clearsilver

CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY}

INSTALL_DIRS=			${WRKSRC}/ruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
