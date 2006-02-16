# $NetBSD: Makefile,v 1.36 2006/02/16 14:24:00 gavan Exp $
#

DISTNAME=		HTML-Parser-3.50
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hpa
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Parser/
COMMENT=		Perl5 module to parse HTML text documents

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset
# needed for some self-test, but this would create a circular
# dependency -- weird.
#DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
