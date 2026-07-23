# $NetBSD: Makefile,v 1.2 2026/07/23 15:15:18 ryoon Exp $

DISTNAME=	neocities-0.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://neocities.org/cli
COMMENT=	Neocities.org CLI and API client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tty-table>=0.12:../../devel/ruby-tty-table
DEPENDS+=	${RUBY_PKGPREFIX}-tty-prompt>=0.23:../../devel/ruby-tty-prompt
DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.8:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-http>=5.3.1:../../www/ruby-http
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-whirly>=0.3:../../devel/ruby-whirly

.include "../../lang/ruby/rubyversion.mk"
# for older Ruby
.if ${RUBY_VER} < 40
DEPENDS+=	${RUBY_PKGPREFIX}-openssl>=3.3:../../security/ruby-openssl
.else
# Remove dependency to ruby-openssl
OVERRIDE_GEMSPEC+=	openssl:
.endif

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	http>=5.3
OVERRIDE_GEMSPEC+=	http-cookie>=1.0
OVERRIDE_GEMSPEC+=	whirly>=0.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
