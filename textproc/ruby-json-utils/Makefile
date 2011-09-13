# $NetBSD: Makefile,v 1.1.1.1 2011/09/13 15:21:01 taca Exp $

DISTNAME=	json-utils-1.6.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flori.github.com/json
COMMENT=	Utilities for handling JSON data
LICENSE=	ruby-license

REPLACE_RUBY=	bin/edit_json.rb bin/prettify_json.rb

DEPENDS+=	${RUBY_PKGPREFIX}-spruz>=0.2.8<0.3:../../devel/ruby-spruz
DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.6<2:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2>=1.0<2:../../meta-pkgs/ruby-gnome2

CONFLICTS+=	ruby[1-9][0-9]-json-utils>=0

post-extract:
	cd ${WRKSRC}; ${FIND} . -xdev -type f -print | ${XARGS} ${CHMOD} g-w

OVERRIDE_GEMSPEC=	gtk2:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
