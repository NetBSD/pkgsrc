# $NetBSD: Makefile,v 1.15 2019/08/11 13:24:34 wiz Exp $

DISTNAME=	Catalyst-View-Jemplate-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-View-Jemplate
COMMENT=	Jemplate view class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Jemplate>=0.19:../../www/p5-Jemplate

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/Jemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
