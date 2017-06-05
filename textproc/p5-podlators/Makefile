# $NetBSD: Makefile,v 1.21 2017/06/05 14:25:01 ryoon Exp $

DISTNAME=	podlators-4.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/podlators/
COMMENT=	Collection of pod related perl modules
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.1,p5-Pod-Simple>=3.06}:../../textproc/p5-Pod-Simple

PERL5_PACKLIST=		auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
