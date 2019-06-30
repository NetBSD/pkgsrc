# $NetBSD: Makefile,v 1.20 2019/06/30 20:17:21 nia Exp $

DISTNAME=		CGI-Application-Plugin-ValidateRM-2.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Application-Plugin-ValidateRM
COMMENT=		Help validate CGI::Application run modes using Data::FormValidator
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=		p5-HTML-FillInForm-[0-9]*:../../www/p5-HTML-FillInForm
DEPENDS+=		p5-Data-FormValidator-[0-9]*:../../textproc/p5-Data-FormValidator
DEPENDS+=		p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA

PERL5_PACKLIST=		auto/CGI/Application/Plugin/ValidateRM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
