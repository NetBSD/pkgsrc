# $NetBSD: Makefile,v 1.1.1.1 2003/10/03 14:26:40 wiz Exp $

DISTNAME=		Template-Generate-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tge
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~autrijus/Template-Generate/
COMMENT=		Perl5 module for generating TT2 templates from TT2-rendered documents

DEPENDS+=		p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Template/Generate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
