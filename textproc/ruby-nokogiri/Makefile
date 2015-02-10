# $NetBSD: Makefile,v 1.25 2015/02/10 19:31:03 joerg Exp $

DISTNAME=	nokogiri-1.6.6.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9][0-9]-nokogiri-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile>=0.6.0<0.7:../../misc/ruby-mini_portile

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		pkg-config
MAKE_ENV+=		NOKOGIRI_USE_SYSTEM_LIBRARIES=yes
OVERRIDE_GEMSPEC=	:files ports/archives/libxml2-2.8.0.tar.gz= \
				ports/archives/libxslt-1.1.26.tar.gz=
RUBY_VERSION_SUPPORTED=	200 193 21

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
