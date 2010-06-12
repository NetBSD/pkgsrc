# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 10:43:12 obache Exp $
#

DISTNAME=	div-1.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.druby.org/ilikeruby/div.en.html
COMMENT=	Simple Web Application framework with dRuby and ERB
#LICENSE=	# TODO: nothing

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=		YES
USE_RUBY_INSTALL=	YES

INSTALL_TARGET=	-d ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
