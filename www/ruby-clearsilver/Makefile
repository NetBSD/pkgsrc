# $NetBSD: Makefile,v 1.14.4.1 2011/02/27 00:26:30 tron Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=			1

PKG_DESTDIR_SUPPORT=		user-destdir

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY:Q}
INSTALLATION_DIRS=		${RUBY_VENDORARCHLIB} ${RUBY_VENDORLIB}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ruby/ext/hdf/hdf.${RUBY_DLEXT} \
		${DESTDIR}${PREFIX}/${RUBY_VENDORARCHLIB}
	${INSTALL_DATA} ${WRKSRC}/ruby/lib/neo.rb \
		${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}/neo.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
