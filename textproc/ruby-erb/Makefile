# $NetBSD: Makefile,v 1.8 2004/03/16 02:01:11 taca Exp $
#

DISTNAME=	erb-1.4.3
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Implementation of eRuby (embedded ruby)

DIST_SUBDIR=	ruby
USE_RUBY=	# defined
NO_BUILD=	# defined

REPLACE_RUBY=	lib/erb/erbcgi.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
