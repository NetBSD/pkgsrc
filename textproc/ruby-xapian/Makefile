# $NetBSD: Makefile,v 1.11 2026/02/03 13:25:02 taca Exp $

PKGNAME=		${RUBY_PKGPREFIX}-${PKGNAME_MODULE}
COMMENT=		Ruby bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/ruby/

CONFIGURE_ARGS+=	--with-ruby
CONFIGURE_ENV+=		RDOC=${RDOC:Q}
MAKE_ENV+=		RUBY_PKGPREFIX=${RUBY_PKGPREFIX:Q}

REPLACE_RUBY=		ruby/docs/examples/*.rb
RUBY_ALLOW_HAS_RDOC=	# empty
RDOCDIR=		share/doc/xapian-bindings/${RUBY_NAME}
RUBY_DYNAMIC_DIRS=	${RDOCDIR}

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/${RUBY_NAME}/examples/*.rb
	${RUBY_GENERATE_PLIST}

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
