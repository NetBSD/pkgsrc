# $NetBSD: Makefile,v 1.8 2003/07/17 22:55:51 grant Exp $

DISTNAME=		HTML-Table-1.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htb
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@NetBSD.org
COMMENT=		perl5 module to simplify creating HTML tables

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
