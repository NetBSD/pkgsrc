# $NetBSD: Makefile,v 1.20 2014/04/25 09:28:57 jperkin Exp $

DISTNAME=	nokogiri-1.6.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9][0-9]-nokogiri-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile>=0.5.0<0.6:../../misc/ruby-mini_portile

USE_GCC_RUNTIME=	yes

MAKE_ENV+=	NOKOGIRI_USE_SYSTEM_LIBRARIES=yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
