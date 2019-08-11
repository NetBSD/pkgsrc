# $NetBSD: Makefile,v 1.18 2019/08/11 13:25:07 wiz Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=			3

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
