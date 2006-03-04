# $NetBSD: Makefile,v 1.3 2006/03/04 21:31:01 jlam Exp $

DISTNAME=		HTML-Element-Extended-1.14
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}
#			${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSISK/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Element-Extended/
COMMENT=		Perl5 modules for managing HTML::Element based objects

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML-Element-Extended/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
