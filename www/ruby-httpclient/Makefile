# $NetBSD: Makefile,v 1.7 2011/10/29 02:18:17 obache Exp $
#

DISTNAME=	httpclient-2.2.3
CATEGORIES=	www

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://github.com/nahi/httpclient
COMMENT=	HTTP accessing library for Ruby
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

# OK with ruby-1.9 buitin one, but not with ruby18's one.
RUBY_RDOC_REQD=	2.5.8

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
