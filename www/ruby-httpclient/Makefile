# $NetBSD: Makefile,v 1.5 2011/06/03 01:44:39 obache Exp $
#

DISTNAME=	httpclient-2.2.1
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/nahi/httpclient
COMMENT=	HTTP accessing library for Ruby
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

# error with ruby18
RUBY_BUILD_RDOC=	no
RUBY_BUILD_RI=		no

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
