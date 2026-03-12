# $NetBSD: Makefile,v 1.11 2026/03/12 15:53:57 taca Exp $

DISTNAME=	sass-embedded-1.98.0
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
CHECK_INTERPRETER_SKIP+=	${GEM_EXTSDIR}/sass/node_modules/.bin/detect-libc
CHECK_INTERPRETER_SKIP+=	${GEM_EXTSDIR}/sass/node_modules/.bin/sass
CHECK_INTERPRETER_SKIP+=	${GEM_EXTSDIR}/sass/node_modules/detect-libc/bin/detect-libc.js
CHECK_INTERPRETER_SKIP+=	${GEM_EXTSDIR}/sass/node_modules/node-addon-api/tools/conversion.js
CHECK_INTERPRETER_SKIP+=	${GEM_EXTSDIR}/sass/node_modules/sass/sass.js

RUBYGEM_OPTIONS+=	--format-executable

GEM_CLEANBUILD=	gem_make.out

# fetch npm files during package build at install stage.
ALLOW_NETWORK_ACCESS=	YES

.include "../../lang/ruby/gem.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
