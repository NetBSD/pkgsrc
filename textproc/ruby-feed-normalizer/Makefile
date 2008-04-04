# $NetBSD: Makefile,v 1.2 2008/04/04 15:21:25 jlam Exp $

DISTNAME=	feed-normalizer-1.5.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://feed-normalizer.rubyforge.org/
COMMENT=	Extensible Ruby wrapper for Atom and RSS parsers

DEPENDS+=	hoe>=1.5.0:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-simple-rss>=1.1:../../textproc/ruby-simple-rss
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
