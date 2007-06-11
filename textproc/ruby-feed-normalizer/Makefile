# $NetBSD: Makefile,v 1.1.1.1 2007/06/11 04:40:37 minskim Exp $

DISTNAME=	feed-normalizer-1.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/20927/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://feed-normalizer.rubyforge.org/
COMMENT=	Extensible Ruby wrapper for Atom and RSS parsers

DEPENDS+=	${RUBY_PKGPREFIX}-simple-rss>=1.1:../../textproc/ruby-simple-rss
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.4:../../textproc/ruby-hpricot

NO_BUILD=	yes
USE_LANGUAGES=	# none

.include "../../lang/ruby/modules.mk"

do-install:
	cd ${WRKSRC}/lib && pax -rwppm . ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/feed-normalizer
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${RUBY_DOCDIR}/feed-normalizer

.include "../../mk/bsd.pkg.mk"
