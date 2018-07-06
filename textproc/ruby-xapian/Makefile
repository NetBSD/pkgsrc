# $NetBSD: Makefile,v 1.3 2018/07/06 16:23:12 schmonz Exp $

PKGNAME=		${RUBY_PKGPREFIX}-${PKGNAME_MODULE}
COMMENT=		Ruby bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/ruby/

CONFIGURE_ARGS+=	--with-ruby
CONFIGURE_ENV+=		RDOC=${RDOC:Q}
MAKE_ENV+=		RUBY_PKGPREFIX=${RUBY_PKGPREFIX:Q}

REPLACE_RUBY=		ruby/docs/examples/*.rb

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/${RUBY_PKGPREFIX}/examples/*.rb

.include "../../lang/ruby/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
