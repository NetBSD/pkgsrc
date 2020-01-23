# $NetBSD: Makefile,v 1.1 2020/01/23 16:14:47 schmonz Exp $

DISTNAME=		YAML-PP-0.018
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://cpan.metacpan.org/authors/id/T/TI/TINITA/
COMMENT=		Modern, modular YAML processor
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/YAML/PP/.packlist
USE_LANGUAGES=		# none

BUILDLINK_API_DEPENDS.p5-Encode+=	p5-Encode>=0
.include "../../textproc/p5-Encode/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
