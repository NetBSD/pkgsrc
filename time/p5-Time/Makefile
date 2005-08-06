# $NetBSD: Makefile,v 1.12 2005/08/06 06:19:35 jlam Exp $

DISTNAME=      	Time-modules-2003.1126
PKGNAME=	p5-${DISTNAME:S/modules-//}
SVR4_PKGNAME=	p5tim
PKGREVISION=	1
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 functions to convert and use time variables

PERL5_PACKLIST=		auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
