# $NetBSD: Makefile,v 1.3 2002/03/16 11:00:17 taca Exp $
#

DISTNAME=	erb-1.4.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	implementation of eRuby (embedded ruby)

DIST_SUBDIR=	ruby
USE_RUBY=	# defined
NO_BUILD=	# defined

REPLACE_RUBY=	lib/erb/erbcgi.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
