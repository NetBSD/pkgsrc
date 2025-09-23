# $NetBSD: Makefile,v 1.5 2025/09/23 03:34:32 taca Exp $

DISTNAME=	sass-embedded-1.93.1
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
