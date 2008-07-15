# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:30:12 abs Exp $

DISTNAME=	Catalyst-Plugin-StackTrace-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-StackTrace/
COMMENT=	Display a stack trace on the debug screen

DEPENDS+=	p5-Catalyst-Runtime>=5.61:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Devel-StackTrace>=0:../../devel/p5-Devel-StackTrace

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/StackTrace/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
