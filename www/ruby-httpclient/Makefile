# $NetBSD: Makefile,v 1.11 2012/10/28 06:31:03 asau Exp $
#

DISTNAME=	httpclient-2.2.7
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/nahi/httpclient
COMMENT=	HTTP accessing library for Ruby
LICENSE=	ruby-license

USE_LANGUAGES=	# none

# OK with ruby-1.9 buitin one, but not with ruby18's one.
RUBY_RDOC_REQD=	2.5.8

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
