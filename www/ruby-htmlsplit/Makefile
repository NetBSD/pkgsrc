# $NetBSD: Makefile,v 1.4 2003/07/17 22:56:02 grant Exp $

DISTNAME=	htmlsplit102
PKGNAME=	${RUBY_PKGNAMEPREFIX}htmlsplit-1.0.2
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.moonwolf.com/ruby/htmlsplit.html
COMMENT=	Ruby HTML split/join library

DIST_SUBDIR=	ruby
USE_RUBY_RD=	# defined
NO_CONFIGURE=	# defined

do-build:
	@cd ${WRKSRC}; ${RUBY_RD} htmlsplit.rb > htmlsplit.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/htmlsplit.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/htmlsplit/ja
	${INSTALL_DATA} ${WRKSRC}/htmlsplit.html ${RUBY_DOCDIR}/htmlsplit/ja
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/htmlsplit
	${INSTALL_DATA} ${WRKSRC}/splittest.rb ${RUBY_EXAMPLESDIR}/htmlsplit

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
