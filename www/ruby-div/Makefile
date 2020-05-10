# $NetBSD: Makefile,v 1.6 2020/05/10 14:01:46 rillig Exp $
#

DISTNAME=	div-1.3.2
CATEGORIES=	www devel ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.druby.org/ilikeruby/div.en.html
COMMENT=	Simple Web Application framework with dRuby and ERB
#LICENSE=	# TODO: nothing

USE_LANGUAGES=	# none

NO_BUILD=		YES
USE_RUBY_INSTALL=	YES
SUBST_NOOP_OK.rinstall=	yes # nothing found for ruby24-div

INSTALL_TARGET=	-d ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
