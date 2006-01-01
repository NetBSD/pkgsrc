# $NetBSD: Makefile,v 1.34 2006/01/01 23:00:30 wiz Exp $
#

DISTNAME=		HTML-Parser-3.48
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hpa
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Parser/
COMMENT=		Perl5 module to parse HTML text documents

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
