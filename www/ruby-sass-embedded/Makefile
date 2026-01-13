# $NetBSD: Makefile,v 1.8 2026/01/13 14:46:55 taca Exp $

DISTNAME=	sass-embedded-1.97.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sass-contrib/sass-embedded-host-ruby
COMMENT=	Use dart-sass with Ruby!
LICENSE=	mit

CONFLICTS+=	${RUBY_PKGPREFIX}-sass-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-google-protobuf>=4.31<5:../../devel/ruby-google-protobuf

#
# It is difficult to replace these files.
#
CHECK_INTERPRETER_SKIP+= \
	${GEM_EXTSDIR}/sass/node_modules/.bin/detect-libc \
	${GEM_EXTSDIR}/sass/node_modules/.bin/sass \
	${GEM_EXTSDIR}/sass/node_modules/detect-libc/bin/detect-libc.js \
	${GEM_EXTSDIR}/sass/node_modules/node-addon-api/tools/conversion.js \
	${GEM_EXTSDIR}/sass/node_modules/sass/sass.js \

RUBYGEM_OPTIONS+=	--format-executable

GEM_CLEANBUILD=	gem_make.out

# fetch npm files during package build at install stage.
ALLOW_NETWORK_ACCESS=	YES

.include "../../lang/ruby/gem.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
