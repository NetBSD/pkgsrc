# $NetBSD: Makefile,v 1.8 2011/11/28 13:05:36 hiramatsu Exp $

DISTNAME=		CGI-Application-Plugin-ValidateRM-2.4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Application-Plugin-ValidateRM/
COMMENT=		Help validate CGI::Application run modes using Data::FormValidator
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=		p5-HTML-FillInForm-[0-9]*:../../www/p5-HTML-FillInForm
DEPENDS+=		p5-Data-FormValidator-[0-9]*:../../textproc/p5-Data-FormValidator

PERL5_PACKLIST=		auto/CGI/Application/Plugin/ValidateRM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
