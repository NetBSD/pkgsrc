# $NetBSD: Makefile,v 1.1.1.1 2001/07/03 14:32:36 taca Exp $
#

DISTNAME=	erb-1.3.3
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	implementation of eRuby (embedded ruby)

DIST_SUBDIR=	ruby
USE_RUBY=	yes

REPLACE_RUBY=	lib/erb/erbcgi.rb
REPLACE_ERBCGI=	sample/cgi_test.rhtml sample/sample.rhtml
FIX_MODES=	lib/erb/erb.rb lib/erb/erbl.rb
EXAMPLES=	cgi_test.rhtml dot.htaccess erbux.rb err.rhtml \
		sample.rhtml succ.rhtml

do-build:
.for f in ${REPLACE_ERBCGI}
	@${ECHO_MSG} "===>  Fixing the #! line of $f"; \
	${RUBY} -i -pe '$$. == 1 and sub /^#!.*\/([a-z]+\.rb)/, "#!${RUBY_SITELIBDIR}/\\1"' ${WRKSRC}/$f
.endfor
.for f in ${FIX_MODES}
	${CHMOD} -x ${WRKSRC}/$f
.endfor

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/erb
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/$f ${RUBY_EXAMPLESDIR}/erb
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
