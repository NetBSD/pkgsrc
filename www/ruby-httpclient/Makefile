# $NetBSD: Makefile,v 1.18 2015/03/15 20:13:24 hiramatsu Exp $
#

DISTNAME=	httpclient-2.6.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nahi/httpclient
COMMENT=	HTTP accessing library for Ruby
LICENSE=	ruby-license

USE_LANGUAGES=	# none

# OK with ruby-1.9 buitin one, but not with ruby18's one.
RUBY_RDOC_REQD=	2.5.8

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
