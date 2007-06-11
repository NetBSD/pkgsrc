# $NetBSD: Makefile,v 1.1.1.1 2007/06/11 17:28:17 minskim Exp $

DISTNAME=	ferret-0.11.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/19358/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ferret.davebalmain.com/
COMMENT=	Text search engine library written for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

do-install:
	cd ${WRKSRC}/lib && pax -rwppm . ${RUBY_SITELIBDIR}
	${INSTALL_LIB} ${WRKSRC}/ext/ferret_ext.${RUBY_DLEXT}		\
		${RUBY_SITEARCHLIBDIR}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
