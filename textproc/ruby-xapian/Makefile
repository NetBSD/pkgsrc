# $NetBSD: Makefile,v 1.9 2022/01/14 16:00:16 taca Exp $

PKGNAME=		${RUBY_PKGPREFIX}-${PKGNAME_MODULE}
COMMENT=		Ruby bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/ruby/

CONFIGURE_ARGS+=	--with-ruby
CONFIGURE_ENV+=		RDOC=${RDOC:Q}
MAKE_ENV+=		RUBY_PKGPREFIX=${RUBY_PKGPREFIX:Q}

REPLACE_RUBY=		ruby/docs/examples/*.rb

PLIST_VARS+=		oldruby newruby
PLIST_SUBST+=		XAPIAN_RDOC_PATH=${XAPIAN_RDOC_PATH:Q}

.include "../../lang/ruby/rubyversion.mk"

PLIST.newruby=		yes
XAPIAN_RDOC_PATH=	Xapian

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/${RUBY_PKGPREFIX}/examples/*.rb

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
