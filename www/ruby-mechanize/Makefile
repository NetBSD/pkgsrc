# $NetBSD: Makefile,v 1.1.1.1 2007/05/26 01:46:51 minskim Exp $

DISTNAME=	mechanize-0.6.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/19657/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites

DEPENDS+=	${RUBY_PKGPREFIX}-hpricot-[0-9]*:../../textproc/ruby-hpricot

USE_LANGUAGES=	# none
USE_RUBY_SETUP=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
