# $NetBSD: Makefile,v 1.8 2011/12/08 12:08:05 obache Exp $
#

DISTNAME=	httpclient-2.2.4
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
