# $NetBSD: Makefile,v 1.1.1.1 2007/06/15 01:05:05 minskim Exp $

DISTNAME=	maruku-0.5.6
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/21120/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://maruku.rubyforge.org/
COMMENT=	Markdown-superset interpreter

NO_BUILD=	yes
USE_LANGUAGES=	# none

REPLACE_RUBY=	bin/*

.include "../../lang/ruby/modules.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
	cd ${WRKSRC}/lib && pax -rwppm . ${RUBY_SITELIBDIR}

.include "../../mk/bsd.pkg.mk"
