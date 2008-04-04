# $NetBSD: Makefile,v 1.2 2008/04/04 15:26:25 jlam Exp $

DISTNAME=	mechanize-0.7.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites

DEPENDS+=	hoe>=1.5.1:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
