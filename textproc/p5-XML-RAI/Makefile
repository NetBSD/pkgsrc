# $NetBSD: Makefile,v 1.23 2017/06/05 14:24:57 ryoon Exp $

DISTNAME=	XML-RAI-1.3031
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Maps RSS tags to one common simplified interface
HOMEPAGE=	http://search.cpan.org/dist/XML-RAI/
LICENSE=	artistic

DEPENDS+=	p5-Task-Weaken>=1.02:../../devel/p5-Task-Weaken
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-XML-RSS-Parser>=4.0:../../textproc/p5-XML-RSS-Parser

BUILD_DEPENDS+=	p5-Test-Weaken-[0-9]*:../../devel/p5-Test-Weaken

PERL5_PACKLIST=		auto/XML/RAI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
