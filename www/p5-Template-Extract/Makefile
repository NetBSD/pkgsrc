# $NetBSD: Makefile,v 1.1.1.1 2003/10/03 14:07:24 wiz Exp $

DISTNAME=		Template-Extract-0.25
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tex
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~autrijus/Template-Extract/
COMMENT=		Perl5 module for extracting data structure from TT2-rendered documents

DEPENDS+=		p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Template/Extract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
