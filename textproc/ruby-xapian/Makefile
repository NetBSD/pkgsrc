# $NetBSD: Makefile,v 1.1 2017/07/10 17:34:04 schmonz Exp $

PKGNAME=		${RUBY_PKGPREFIX}-${PKGNAME_MODULE}
COMMENT=		Ruby bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/ruby/

CONFIGURE_ARGS+=	--with-ruby

REPLACE_RUBY=		ruby/docs/examples/*.rb

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/ruby/examples/*.rb

.include "../../lang/ruby/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
