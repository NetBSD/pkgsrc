# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:56 asau Exp $
#

DISTNAME=	hikidoc-0.0.6
PKGREVISION=	1
CATEGORIES=	textproc converters ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/72253/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://projects.netlab.jp/hikidoc/
COMMENT=	Text-to-HTML conversion tool for web writers
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_RUBY_SETUP=	YES

DOCDIR=		${RUBY_DOC}/hikidoc
DOCS=		NEWS NEWS.ja README README.ja \
		TextFormattingRules TextFormattingRules.ja

CONFIGURE_ARGS+=	--siterubyver=${PREFIX}/${RUBY_VENDORLIB}
REPLACE_RUBY+=		bin/hikidoc
INSTALLATION_DIRS=	${RUBY_DOC}/hikidoc

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

do-test:
	${RUN} cd ${WRKSRC}; ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
