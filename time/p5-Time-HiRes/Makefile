# $NetBSD: Makefile,v 1.2 2002/10/20 17:46:02 seb Exp $
#

DISTNAME=		Time-HiRes-01.20
PKGNAME=		p5-Time-HiRes-01.20
SVR4_PKGNAME=		p5thr
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@netbsd.org
COMMENT=		perl5 module for high resolution time, sleep, and alarm

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/HiRes/.packlist

WRKSRC=			${WRKDIR}/Time-HiRes-01.20

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
