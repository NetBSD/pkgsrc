# $NetBSD: Makefile,v 1.26 2019/08/11 13:24:00 wiz Exp $

DISTNAME=	podlators-4.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/podlators
COMMENT=	Collection of pod related perl modules
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.1,p5-Pod-Simple>=3.06}:../../textproc/p5-Pod-Simple

PERL5_PACKLIST=		auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
