# $NetBSD: Makefile,v 1.3 2009/12/02 14:04:22 fhajny Exp $

DISTNAME=	mechanize-0.9.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	hoe>=1.12.2:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.2.1:../../textproc/ruby-nokogiri

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
