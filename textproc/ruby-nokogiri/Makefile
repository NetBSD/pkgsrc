# $NetBSD: Makefile,v 1.56 2020/11/05 09:09:15 ryoon Exp $

DISTNAME=	nokogiri-1.10.10
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile2>=2.4.0:../../misc/ruby-mini_portile2

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		pkg-config
MAKE_ENV+=		NOKOGIRI_USE_SYSTEM_LIBRARIES=yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	mini_portile2>=2.4.0 \
			:files ports/archives/libxml2-2.9.10.tar.gz= \
			ports/archives/libxslt-1.1.34.tar.gz=

.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
