# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:22:40 jlam Exp $

DISTNAME=	camping-1.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.whytheluckystiff.net/camping
COMMENT=	Ruby micro-framework for web applications

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.3.1:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-markaby>=0.5:../../textproc/ruby-markaby
DEPENDS+=	${RUBY_PKGPREFIX}-metaid>=1.0:../../devel/ruby-metaid

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
