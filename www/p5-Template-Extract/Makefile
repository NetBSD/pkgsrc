# $NetBSD: Makefile,v 1.4 2004/12/20 11:31:14 grant Exp $

DISTNAME=		Template-Extract-0.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5tex
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~autrijus/Template-Extract/
COMMENT=		Perl5 module for extracting data structure from TT2-rendered documents

DEPENDS+=		p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Template/Extract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
