# $NetBSD: Makefile,v 1.34 2014/05/29 23:38:00 wiz Exp $

DISTNAME=		CGI-Application-4.50
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
SVR4_PKGNAME=		p5cga
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Application/
COMMENT=		Perl5 module to create sophisticated, reusable web-based applications
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Application/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
