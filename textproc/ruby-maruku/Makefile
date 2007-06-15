# $NetBSD: Makefile,v 1.2 2007/06/15 01:10:21 minskim Exp $

DISTNAME=	maruku-0.5.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/21120/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://maruku.rubyforge.org/
COMMENT=	Markdown-superset interpreter

NO_BUILD=	yes
USE_LANGUAGES=	# none

.include "../../lang/ruby/modules.mk"

do-install:
	cd ${WRKSRC}/lib && pax -rwppm . ${RUBY_SITELIBDIR}

.include "../../mk/bsd.pkg.mk"
