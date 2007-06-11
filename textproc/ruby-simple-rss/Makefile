# $NetBSD: Makefile,v 1.1.1.1 2007/06/11 04:03:51 minskim Exp $

DISTNAME=	simple-rss-1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/8346/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://simple-rss.rubyforge.org/
COMMENT=	Simple, flexible, extensible, and liberal RSS and Atom reader

NO_BUILD=	yes
USE_LANGUAGES=	# none

.include "../../lang/ruby/modules.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/simple-rss.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/simple-rss
	cd ${WRKSRC}/html && pax -rwppm . ${RUBY_DOCDIR}/simple-rss

.include "../../mk/bsd.pkg.mk"
