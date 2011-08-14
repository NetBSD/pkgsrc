# $NetBSD: Makefile,v 1.8 2011/08/14 16:05:50 obache Exp $

DISTNAME=	Catalyst-Plugin-StackTrace-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-StackTrace/
COMMENT=	Display a stack trace on the debug screen
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.70:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Devel-StackTrace>=0:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-MRO-Compat>=0.10:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/StackTrace/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
