# $NetBSD: Makefile,v 1.30 2022/06/28 11:36:48 wiz Exp $

DISTNAME=	podlators-4.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/podlators
COMMENT=	Collection of pod related perl modules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
