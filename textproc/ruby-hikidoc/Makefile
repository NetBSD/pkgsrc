# $NetBSD: Makefile,v 1.2 2010/08/27 05:06:17 obache Exp $
#

DISTNAME=	hikidoc-0.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/72248/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://projects.netlab.jp/hikidoc/
COMMENT=	Text-to-HTML conversion tool for web writers
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_RUBY_SETUP=	YES

CONFIGURE_ARGS+=	--siterubyver=${PREFIX}/${RUBY_VENDORLIB}

do-test:
	${RUN} cd ${WRKSRC}; ${RUBY} test/run-test.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
