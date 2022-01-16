# $NetBSD: Makefile,v 1.68 2022/01/16 10:12:07 tsutsui Exp $

DISTNAME=	nokogiri-1.13.1
CATEGORIES=	textproc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile2>=2.7.0:../../misc/ruby-mini_portile2

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		pkg-config
MAKE_ENV+=		NOKOGIRI_USE_SYSTEM_LIBRARIES=yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	:files ports/archives/libxml2-2.9.12.tar.gz= \
			ports/archives/libxslt-1.1.34.tar.gz=

# XXX: work around bug in bootstrap-mk-files, remove when fixed
MAKE_ENV.SunOS+=	ARFLAGS=rcv

.include "../../lang/ruby/rubyversion.mk"
# Ruby 2.7 and later bundles racc
.if ${RUBY_VER} == "26"
DEPENDS+=	${RUBY_PKGPREFIX}-racc>=1.4.0:../../devel/ruby-racc
.endif

.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
