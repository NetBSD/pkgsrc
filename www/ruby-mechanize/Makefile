# $NetBSD: Makefile,v 1.4 2010/09/10 13:54:48 taca Exp $

DISTNAME=	mechanize-1.0.0
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mechanize.rubyforge.org/
COMMENT=	Library to automate interaction with websites
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.2.1:../../textproc/ruby-nokogiri

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
