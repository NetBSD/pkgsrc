# $NetBSD: Makefile,v 1.3 2025/08/11 15:59:21 taca Exp $

DISTNAME=	sass-embedded-1.89.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sass-contrib/sass-embedded-host-ruby
COMMENT=	Use dart-sass with Ruby!
LICENSE=	mit

CONFLICTS+=	${RUBY_PKGPREFIX}-sass-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-google-protobuf>=4.31<5:../../devel/ruby-google-protobuf

RUBYGEM_OPTIONS+=	--format-executable

GEM_CLEANBUILD=	gem_make.out

# fetch npm files during package build at install stage.
ALLOW_NETWORK_ACCESS=	YES

.include "../../lang/ruby/gem.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
