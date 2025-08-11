# $NetBSD: Makefile,v 1.1 2025/08/11 12:00:35 ryoon Exp $

DISTNAME=	neocities-0.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://neocities.org/cli
COMMENT=	Neocities.org CLI and API client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tty-table>=0.10:../../devel/ruby-tty-table
DEPENDS+=	${RUBY_PKGPREFIX}-tty-prompt>=0.12:../../devel/ruby-tty-prompt
DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.7:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-http>=5.3:../../www/ruby-http
DEPENDS+=	${RUBY_PKGPREFIX}-whirly>=0.3:../../devel/ruby-whirly

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	tty-table>=0.12.0
OVERRIDE_GEMSPEC+=	unicode-display_width>=3.1.0
OVERRIDE_GEMSPEC+=	tty-prompt>=0.23.0
OVERRIDE_GEMSPEC+=	pastel>=0.8.0
OVERRIDE_GEMSPEC+=	rake>=13

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
