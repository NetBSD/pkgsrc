# $NetBSD: Makefile,v 1.21 2019/08/11 13:24:07 wiz Exp $

DISTNAME=	DateTime-Format-Mail-0.403
# make sure it has 4 digits
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-Mail
COMMENT=	Convert between DateTime and RFC2822/822 formats
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.18:../../time/p5-DateTime
#DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Params-Validate>=0.67:../../devel/p5-Params-Validate

PERL5_PACKLIST= auto/DateTime/Format/Mail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
