# $NetBSD: Makefile,v 1.7 2004/11/12 18:40:14 kristerw Exp $

DISTNAME=	tag104
PKGNAME=	${RUBY_PKGNAMEPREFIX}tag-1.0.4
CATEGORIES=	www ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.moonwolf.com/ruby/tag.html
COMMENT=	Ruby Simple HTML Tag library for CGI

# The distfile cannot be extracted with some tar (e.g. NetBSD 2.0)
# or some pax (e.g. NetBSD 1.6).  Force use of gtar instead.
BUILD_DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base
GTAR=		${PREFIX}/bin/${GNU_PROGRAM_PREFIX}tar

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	ruby
USE_RUBY_RD=	# defined
NO_CONFIGURE=	# defined

do-build:
	@cd ${WRKSRC}; ${RUBY_RD} tag.rb > tag.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/tag.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tag/ja
	${INSTALL_DATA} ${WRKSRC}/tag.html ${RUBY_DOCDIR}/tag/ja

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
