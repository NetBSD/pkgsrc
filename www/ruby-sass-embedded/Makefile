# $NetBSD: Makefile,v 1.16 2026/09/06 16:23:23 taca Exp $

DISTNAME=	sass-embedded-1.104.0
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

PLIST_SUBST+=		PKGVERSION_NOREV=${PKGVERSION_NOREV}

.include "../../lang/ruby/gem.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../mk/bsd.pkg.mk"
