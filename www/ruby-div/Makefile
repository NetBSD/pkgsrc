# $NetBSD: Makefile,v 1.3 2012/10/28 06:31:03 asau Exp $
#

DISTNAME=	div-1.3.2
CATEGORIES=	www devel ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.druby.org/ilikeruby/div.en.html
COMMENT=	Simple Web Application framework with dRuby and ERB
#LICENSE=	# TODO: nothing

USE_LANGUAGES=	# none

NO_BUILD=		YES
USE_RUBY_INSTALL=	YES

INSTALL_TARGET=	-d ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
