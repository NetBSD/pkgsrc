# $NetBSD: Makefile,v 1.32 2016/10/18 14:41:15 taca Exp $

DISTNAME=	nokogiri-1.6.8.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config>=1.1.7<1.2:../../devel/ruby-pkg-config
DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile2>=2.1.0:../../misc/ruby-mini_portile2

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		pkg-config
MAKE_ENV+=		NOKOGIRI_USE_SYSTEM_LIBRARIES=yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	:files ports/archives/libxml2-2.9.2.tar.gz= \
				ports/archives/libxslt-1.1.28.tar.gz=

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
