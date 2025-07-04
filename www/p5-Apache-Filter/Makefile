# $NetBSD: Makefile,v 1.42 2025/07/04 08:48:56 wiz Exp $

DISTNAME=	Apache-Filter-1.024
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Apache-Filter
COMMENT=	Perl5 module to alter the output of previous Apache handlers

PERL5_PACKLIST=		auto/Apache/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
