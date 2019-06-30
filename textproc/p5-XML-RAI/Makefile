# $NetBSD: Makefile,v 1.25 2019/06/30 20:17:09 nia Exp $

DISTNAME=	XML-RAI-1.3031
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Maps RSS tags to one common simplified interface
HOMEPAGE=	https://metacpan.org/release/XML-RAI
LICENSE=	artistic

DEPENDS+=	p5-Task-Weaken>=1.02:../../devel/p5-Task-Weaken
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-XML-RSS-Parser>=4.0:../../textproc/p5-XML-RSS-Parser

BUILD_DEPENDS+=	p5-Test-Weaken-[0-9]*:../../devel/p5-Test-Weaken

PERL5_PACKLIST=		auto/XML/RAI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
