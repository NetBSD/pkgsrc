# $NetBSD: Makefile,v 1.25 2023/07/06 09:42:17 wiz Exp $

DISTNAME=	Time-TAI64-2.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-TAI64
COMMENT=	Convert TAI64 strings into standard unix timestamps

#TOOL_DEPENDS+=	{perl>=5.6.2,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple
#DEPENDS+=		{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Time/TAI64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
