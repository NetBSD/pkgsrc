# $NetBSD: Makefile,v 1.6 2003/10/14 08:26:34 taca Exp $

DISTNAME=	htmlsplit102
PKGNAME=	${RUBY_PKGNAMEPREFIX}htmlsplit-1.0.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.moonwolf.com/ruby/htmlsplit.html
COMMENT=	Ruby HTML split/join library

DIST_SUBDIR=	ruby
USE_RUBY=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_DATA} ${WRKSRC}/htmlsplit.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/htmlsplit
	${INSTALL_DATA} ${WRKSRC}/splittest.rb ${RUBY_EXAMPLESDIR}/htmlsplit

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
