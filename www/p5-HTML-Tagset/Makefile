# $NetBSD: Makefile,v 1.19 2005/11/23 22:16:36 wiz Exp $
#

DISTNAME=		HTML-Tagset-3.10
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htg
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Tagset/
COMMENT=		Perl5 module of data tables useful in parsing HTML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Tagset/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
