# $NetBSD: Makefile,v 1.5 2011/08/14 16:05:47 obache Exp $

DISTNAME=	Catalyst-Controller-BindLex-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Controller::BindLex
COMMENT=	Put lexicals on the catalyst stash

DEPENDS+=       p5-Array-RefElem>=0:../../devel/p5-Array-RefElem
DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Devel-Caller>0:../../devel/p5-Devel-Caller
DEPENDS+=	p5-Devel-LexAlias>0:../../devel/p5-Devel-LexAlias
DEPENDS+=       p5-Test-use-ok>=0:../../devel/p5-Test-use-ok
DEPENDS+=	p5-PadWalker>0:../../devel/p5-PadWalker

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Controller/BindLex/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
