# $NetBSD: Makefile,v 1.7 2003/07/21 17:27:51 martti Exp $
#

DISTNAME=	erb-1.4.3
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
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
