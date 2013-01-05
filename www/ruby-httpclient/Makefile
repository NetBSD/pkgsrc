# $NetBSD: Makefile,v 1.12 2013/01/05 05:46:11 obache Exp $
#

DISTNAME=	httpclient-2.3.2
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/nahi/httpclient
COMMENT=	HTTP accessing library for Ruby
LICENSE=	ruby-license

USE_LANGUAGES=	# none

# OK with ruby-1.9 buitin one, but not with ruby18's one.
RUBY_RDOC_REQD=	2.5.8

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
