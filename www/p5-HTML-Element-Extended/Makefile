# $NetBSD: Makefile,v 1.1.1.1 2005/10/25 13:33:57 wiz Exp $

DISTNAME=		HTML-Element-Extended-1.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}
#			${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSISK/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Element-Extended/
COMMENT=		Perl5 modules for managing HTML::Element based objects

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML-Element-Extended/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
