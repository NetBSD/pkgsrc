# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 14:15:55 taca Exp $

DISTNAME=	htmlsplit102
PKGNAME=	${RUBY_PKGNAMEPREFIX}htmlsplit-1.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.moonwolf.com/ruby/htmlsplit.html
COMMENT=	Ruby HTML split/join library

DIST_SUBDIR=	ruby
WRKSRC=		${WRKDIR}
USE_RUBY=	yes
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
