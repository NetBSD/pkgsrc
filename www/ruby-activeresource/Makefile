# $NetBSD: Makefile,v 1.2 2008/04/04 15:30:02 jlam Exp $

DISTNAME=	activeresource-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activeresource/
COMMENT=	Object-relational mapping for REST webservices

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2nb1:../../devel/ruby-activesupport

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
