# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:29 wiz Exp $

DISTNAME=	Catalyst-Controller-BindLex-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Catalyst::Controller::BindLex
COMMENT=	Put lexicals on the catalyst stash

DEPENDS+=       p5-Array-RefElem>=0:../../devel/p5-Array-RefElem
DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Devel-Caller>0:../../devel/p5-Devel-Caller
DEPENDS+=	p5-Devel-LexAlias>0:../../devel/p5-Devel-LexAlias
DEPENDS+=       p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
DEPENDS+=	p5-PadWalker>0:../../devel/p5-PadWalker

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Controller/BindLex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
